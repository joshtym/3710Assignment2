#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "PentadraPair.h"

PentadraPair::PentadraPair()
{	
	xOriginValue = 0;
	yOriginValue = 0;
	zOriginValue = 0;	
}

PentadraPair::PentadraPair(double xAlteration, double yAlteration, double zAlteration)
{	
	xOriginValue = xAlteration;
	yOriginValue = yAlteration;
	zOriginValue = zAlteration;
}

PentadraPair::~PentadraPair()
{
}

void PentadraPair::drawPentadraPair()
{	
	glTranslatef(xOriginValue, yOriginValue, zOriginValue);
	
	int iterateAmount = 0;
	int currentArrayNumber = 0;
	
	for (int i = 0; i < 10; ++i)
	{		
		if (i < 5)
			glColor3f(colourOne[0], colourOne[1], colourOne[2]);
		else
			glColor3f(colourTwo[0], colourTwo[1], colourTwo[2]);
		
		if (i == 2 || i == 4 || i == 7 || i == 9)
			iterateAmount = 3;
		else
			iterateAmount = 4;
			
		
		glBegin(GL_POLYGON);
			for (int j = 0; j < iterateAmount; j++)
			{
				if (currentArrayNumber >= 18)
					glVertex3f(xValues[currentArrayNumber - 18], yValues[currentArrayNumber - 18], (zValues[currentArrayNumber - 18]) * -1);
				else
					glVertex3f(xValues[currentArrayNumber], yValues[currentArrayNumber], zValues[currentArrayNumber]);
					
				currentArrayNumber++;
			}
		glEnd();
	}
	
	glCullFace(GL_BACK);
}

void PentadraPair::rotatePoints(double theta, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis)
{
	glTranslatef(xOriginValue, yOriginValue, zOriginValue);
	glRotatef(theta, xAxis, yAxis, zAxis);
	glTranslatef(xOriginValue * -1, yOriginValue * -1, zOriginValue * -1);
}

void PentadraPair::drawAndRotate(double theta, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis)
{
	glPushMatrix();
		rotatePoints(theta, xAxis, yAxis, zAxis);
		drawPentadraPair();
	glPopMatrix();
}
