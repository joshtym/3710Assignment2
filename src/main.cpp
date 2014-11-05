#include <GL/glut.h>

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

// Function which changes which axxis is being rotated about when
// key is pressed
void changeAxisRotation(double, double, double);

// Global Variables
static GLfloat spin = 0.0;
static bool isRotating = true;

// Axis details (which axis we are rotating about)
static GLfloat xAxisRotation = 1.0;
static GLfloat yAxisRotation = 0.0;
static GLfloat zAxisRotation = 0.0;

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
}

//***************************************************************
// Function: display
// Purpose: Handle all display. This includes drawing, rotation and 
//          handling of the OpenGL pipeline
//***************************************************************
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Push matrix on to the stack
	glPushMatrix();
	
	// Rotate object dependent on spin angle and axis vlaues
	glRotatef(spin, xAxisRotation, yAxisRotation, zAxisRotation);
	
	// Begin drawing the Pentadra
	
	// Draw pentadra red flavour face 1 
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.00, 0.00, 0.00);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.00, 0.00, -1.00);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.50, 0.00, -1.00);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.75, 0.00, -0.75);
	glEnd();
	
	// Draw pentadra red flavour face 2
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.50, 0.50, -0.50);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.25, 0.25, -1.00);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.00, 0.00, -1.00);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.00, 0.00, 0.00);
	glEnd();
	
	// Draw pentadra red flavour face 3
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.25, 0.25, -1.00);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.50, 0.00, -1.00);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.00, 0.00, -1.00);
	glEnd();
	
	// Draw pentadra red flavour face 4
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.25, 0.25, -1.00);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.50, 0.50, -0.50);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.75, 0.00, -0.75);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.50, 0.00, -1.00);
	glEnd();
	
	// Draw pentadra red flavour face 5
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.50, 0.50, -0.50);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.00, 0.00, 0.00);
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.75, 0.00, -0.75);
	glEnd();
	
	// Draw pentadra green flavour face 1
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.00, 0.00, 0.00);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.00, 0.00, 1.00);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.50, 0.00, 1.00);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.75, 0.00, 0.75);
	glEnd();
	
	// Draw pentadra green flavour face 2
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.50, 0.50, 0.50);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.25, 0.25, 1.00);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.00, 0.00, 1.00);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.00, 0.00, 0.00);
	glEnd();
	
	// Draw pentadra green flavour face 3
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.25, 0.25, 1.00);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.50, 0.00, 1.00);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.00, 0.00, 1.00);
	glEnd();
	
	// Draw pentadra green flavour face 4
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.25, 0.25, 1.00);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.50, 0.50, 0.50);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.75, 0.00, 0.75);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.50, 0.00, 1.00);
	glEnd();
	
	// Draw pentadra green flavour face 5
	glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.50, 0.50, 0.50);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.00, 0.00, 0.00);
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.75, 0.00, 0.75);
	glEnd();
	
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
	spin = spin + 0.10;
	
	if (spin > 360.0)
		spin = spin - 360;
	
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	/* Viewing Transformation
	 * sets the eye to be at (1.5, 1.5, 1.5) looking at the origin etc.
	*/
	gluLookAt(1.5, 1.5, 1.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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
	{
		glutIdleFunc(NULL);
		isRotating = false;
	}
	else
	{
		glutIdleFunc(action);
		isRotating = true;
	}
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
