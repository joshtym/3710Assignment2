#include <GL/glut.h>
#include "PentadraPair.h"
#include <cmath>
#include <iostream>

// Function Prototypes

// Handles initialization with OpenGL
void init();

// Display function that OpenGL calls
void display();

// Spinning animation
void action();

// Keyboard Input Handler
void keyboard(unsigned char key, int xPos, int yPos);

// Mouse Input Handler
void mouse(int button, int state, int xPos, int yPos);

// Function to handle resizing of the window
void reshape(int width, int height);

// Function to handle rotation when input is detected
void rotationHelperFunc();

// Function which changes which axis is being rotated about when
// key is pressed

void changeAxisRotation(double, double, double);

double* computeCrossProduct (double[], double[]);
void rotateAboutArbitraryAxis(double[], GLfloat, GLfloat, GLfloat, double);
void processSpecialKeys(int, int, int);

// Global Variables
static GLfloat spin = 0.0;
static bool isRotating = true;
static double PI = 3.14159265358979;
static int screenWidth = 500;
static int screenHeight = 500;

// Axis details (which axis we are rotating about)
static GLfloat xAxisRotation = 1.0;
static GLfloat yAxisRotation = 0.0;
static GLfloat zAxisRotation = 0.0;

static double VPN[3];
static double VUP[3];
static double VRP[3];
static PentadraPair newPentadraTest(1, 1, 1);

int main(int argc, char **argv)
{
	/* Supplied -- Do not change! */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	
	init();
	
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(action);
	glutMainLoop();
	
	return 0;
}

// Function Definitions

//***************************************************************
// Function: init
// Purpose: Initialize the OpenGL window with the appropiate colour and
//          shade modelling
//***************************************************************
void init()
{
	// Clear the colour to black and set appropiate ShadeModeling
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	
	VRP[0] = 0;
	VRP[1] = 0;
	VRP[2] = 5;
	
	VPN[0] = 0;
	VPN[1] = 0;
	VPN[2] = -1;
	
	VUP[0] = 0;
	VUP[1] = 1;
	VUP[2] = 0;
}

//***************************************************************
// Function: display
// Purpose: Handle all display. This includes drawing, rotation and 
//          handling of the OpenGL pipeline
//***************************************************************
void display()
{
	//PentadraPair pentadraTest2(0,0,0);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* set the viewing area -- use perspective projection
	 * an object at the origin that is about 1 or 2 units wide should
	 * be nicely visible
	*/
	//glFrustum(-1.0, 1.0, -1.0, 1.0, 0.5, 15.0);
	gluPerspective(60.0, (GLfloat) screenWidth/(GLfloat) screenHeight,0.1, 25.0);
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/* Viewing Transformation
	 * sets the eye to be at (1.5, 1.5, 1.5) looking at the origin etc.
	*/
	
	double newPoint[] = {VRP[0] + VPN[0], VRP[1] + VPN[1], VRP[2] + VPN[2]};
	//gluLookAt(1.5, 1.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt(VRP[0], VRP[1], VRP[2], VRP[0] + VPN[0], VRP[1] + VPN[1], VRP[2] + VPN[2], VUP[0], VUP[1], VUP[2]);
	//gluLookAt(VRP[0] + VPN[0], VRP[1] + VPN[1], VRP[2] + VPN[2], VRP[0], VRP[1], VRP[2], VUP[0], VUP[1], VUP[2]);
	
	// Push matrix on to the stack
	glPushMatrix();
	
	// Rotate object dependent on spin angle and axis vlaues
	newPentadraTest.rotatePoints(spin, xAxisRotation, yAxisRotation, zAxisRotation);
	//pentadraTest2.rotatePoints(spin, xAxisRotation, yAxisRotation, zAxisRotation);
	
	// Begin drawing the Pentadra
	 
	newPentadraTest.drawPentadraPair();
	//pentadraTest2.drawPentadraPair();
	
	// Pop the matrix off the stack, swap the two buffers and flush
	// it out of the OpenGL pipe
	glPopMatrix();
	glutSwapBuffers();
	glFlush();
}

//***************************************************************
// Function: action
// Purpose: Updates angle for the rotation of the object
//***************************************************************
void action()
{
	if (isRotating)
	{
		spin = spin + 0.10;
	
		if (spin > 360.0)
			spin = spin - 360;
	}
	
	glutPostRedisplay();
}

//***************************************************************
// Function: keyboard
// Purpose: Handles all keyboard input. If input is the ESC key, close
//          the program. If input is either x, y, or z, use the helper
//          function to change which axis we are rotating about.
//          If the key is r, begin or stop rotation depending on
//          whether it is currently going
//***************************************************************
void keyboard(unsigned char key, int xPos, int yPos)
{
	switch(key)
	{
		// ESC Key
		case 27:
			glutDestroyWindow(1);
			break;
		// 'r' key
		case 82:
			rotationHelperFunc();
			break;
		// 'R' key
		case 114:
			rotationHelperFunc();
			break;
		// 'x' key
		case 88:
			changeAxisRotation(1.0, 0.0, 0.0);
			break;
		// 'X' key
		case 120:
			changeAxisRotation(1.0, 0.0, 0.0);
			break;
		// 'y' key
		case 89:
			changeAxisRotation(0.0, 1.0, 0.0);
			break;
		// 'Y' key
		case 121:
			changeAxisRotation(0.0, 1.0, 0.0);
			break;
		// 'z' key
		case 90:
			changeAxisRotation(0.0, 0.0, 1.0);
			break;
		// 'Z' key
		case 122:
			changeAxisRotation(0.0, 0.0, 1.0);
			break;
		case 32:
			VRP[0] = VRP[0] + VPN[0];
			VRP[1] = VRP[1] + VPN[1];
			VRP[2] = VRP[2] + VPN[2];
			break;
		case 66:
			VRP[0] = VRP[0] - VPN[0];
			VRP[1] = VRP[1] - VPN[1];
			VRP[2] = VRP[2] - VPN[2];
			break;
		case 98:
			VRP[0] = VRP[0] - VPN[0];
			VRP[1] = VRP[1] - VPN[1];
			VRP[2] = VRP[2] - VPN[2];
			break;
		case 78:
			rotateAboutArbitraryAxis(VUP, VPN[0], VPN[1], VPN[2], PI/10);
			break;
		case 110:
			rotateAboutArbitraryAxis(VUP, VPN[0], VPN[1], VPN[2], PI/10);
			break;
		case 77:
			rotateAboutArbitraryAxis(VUP, VPN[0], VPN[1], VPN[2], PI/10 * -1);
			break;
		case 109:
			rotateAboutArbitraryAxis(VUP, VPN[0], VPN[1], VPN[2], PI/10 * -1);
			break;
		default:
			break;
	}
			
}

void processSpecialKeys(int key, int xx, int yy)
{
	double crossVupVpn[3];
	crossVupVpn[0] = computeCrossProduct(VUP, VPN)[0];
	crossVupVpn[1] = computeCrossProduct(VUP, VPN)[1];
	crossVupVpn[2] = computeCrossProduct(VUP, VPN)[2];
	switch (key)
	{
		case GLUT_KEY_LEFT:
			rotateAboutArbitraryAxis(VPN, VUP[0], VUP[1], VUP[2], PI/10);
			break;
		case GLUT_KEY_RIGHT:
			rotateAboutArbitraryAxis(VPN, VUP[0], VUP[1], VUP[2], PI/10 * -1);
			break;
			break;
		case GLUT_KEY_UP:
			rotateAboutArbitraryAxis(VUP, crossVupVpn[0], crossVupVpn[1], crossVupVpn[2], PI/10 * -1);
			rotateAboutArbitraryAxis(VPN, crossVupVpn[0], crossVupVpn[1], crossVupVpn[2], PI/10 * -1);
			break;
		case GLUT_KEY_DOWN:
			rotateAboutArbitraryAxis(VUP, crossVupVpn[0], crossVupVpn[1], crossVupVpn[2], PI/10);
			rotateAboutArbitraryAxis(VPN, crossVupVpn[0], crossVupVpn[1], crossVupVpn[2], PI/10);
			break;
		default:
			break;
	}
}

//***************************************************************
// Function: Mouse
// Purpose: Handles all mouse input. Currently, this program does
//          not have any mouse functionality
//***************************************************************
void mouse(int button, int state, int xPos, int yPos)
{
	switch(button)
	{
		case GLUT_LEFT_BUTTON:
			break;
		case GLUT_RIGHT_BUTTON:
			break;
		default:
			break;
	}
}

//***************************************************************
// Function: reshape
// Purpose: Handles resizing of the OpenGL window
//***************************************************************
void reshape(int width, int height)
{
	/* Supplied -- Do not change! */
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	/* set the viewing area -- use perspective projection
	 * an object at the origin that is about 1 or 2 units wide should
	 * be nicely visible
	*/
	glFrustum(-1.0, 1.0, -1.0, 1.0, 0.5, 15.0);
	//gluPerspective(60.0, (GLfloat) width/(GLfloat) height,0.1, 25.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/* Viewing Transformation
	 * sets the eye to be at (1.5, 1.5, 1.5) looking at the origin etc.
	*/
	//gluLookAt(1.5, 1.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	gluLookAt(VRP[0], VRP[1], VRP[2], VRP[0] + VPN[0], VRP[1] + VPN[1], VRP[2] + VPN[2], VUP[0], VUP[1], VUP[2]);
	//gluLookAt(VRP[0] + VPN[0], VRP[1] + VPN[1], VRP[2] + VPN[2], VRP[0], VRP[1], VRP[2], VUP[0], VUP[1], VUP[2]);
	
	screenWidth = width;
	screenHeight = height;
}


//***************************************************************
// Function: Rotation Helper
// Purpose: Essentially checks if the object is currently rotating
//          when the 'r' key is pressed. If so, stop rotation and set
//          isRotating to false, else, start rotation and set it to true
//***************************************************************
void rotationHelperFunc()
{
	if (isRotating)
		isRotating = false;
	else
		isRotating = true;
}

//***************************************************************
// Function: Axis Rotation Changer
// Purpose: Changes the axis values to the values which are passed in
//***************************************************************
void changeAxisRotation(double xAxis, double yAxis, double zAxis)
{
	xAxisRotation = xAxis;
	yAxisRotation = yAxis;
	zAxisRotation = zAxis;
}

double* computeCrossProduct (double vector1[3], double vector2[3])
{
	double crossProductVector[3];
	
	crossProductVector[0] = vector1[1]*vector2[2] - vector1[2]*vector2[1];
	crossProductVector[1] = (vector1[2]*vector2[0] - vector1[0]*vector2[2]) * -1;
	crossProductVector[2] = vector1[0]*vector2[1] - vector1[1]*vector2[0];
	
	return crossProductVector;
}

void rotateAboutArbitraryAxis(double* A, GLfloat uX, GLfloat uY, GLfloat uZ, double theta) 
{
	double ct, st, lv0, lv1, lv2;
	
	ct = cos(theta);
	st = sin(theta);
	
	lv0 = A[0];
	lv1 = A[1];
	lv2 = A[2];
	
	A[0] = lv0 * (uX*uX + ct * (1.0 - uX*uX)) + lv1 * (uX*uY * (1.0 - ct) - uZ * st) + lv2 * (uZ * uX * (1.0 - ct) + uY * st);
	A[1] = lv0 * (uX*uY * (1.0 - ct) + uZ*st) + lv1 * (uY*uY +  ct * (1.0 - uY*uY)) +lv2 * (uY*uZ * (1.0 - ct) - uX*st);
	A[2] = lv0 * (uZ*uX * (1.0 - ct) - uY*st) + lv1 * (uY*uZ * (1.0 - ct) + uX*st) + lv2 * (uZ*uZ +  ct * (1.0 - uZ*uZ));
}
