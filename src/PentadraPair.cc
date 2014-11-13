#include "PentadraPair.h"

PentadraPair::PentadraPair()
{
	// Initial origin values to 0
	xOriginValue = 0;
	yOriginValue = 0;
	zOriginValue = 0;	
}

PentadraPair::PentadraPair(double xAlteration, double yAlteration, double zAlteration)
{
	// Initial origin values to given point. This helps us define where
	// the shape will actually be drawn
	xOriginValue = xAlteration;
	yOriginValue = yAlteration;
	zOriginValue = zAlteration;
}

PentadraPair::~PentadraPair()
{
}

void PentadraPair::drawPentadraPair()
{
	// Draw the shape at the appropiate position
	glTranslatef(xOriginValue, yOriginValue, zOriginValue);
	
	// Algorithm to iterate through all the points and draw all the points
	int iterateAmount = 0;
	int currentArrayNumber = 0;
	
	for (int i = 0; i < 10; ++i)
	{	
		if (i == 2 || i == 4 || i == 7 || i == 9)
			iterateAmount = 3;
		else
			iterateAmount = 4;
			
		
		glBegin(GL_POLYGON);
			for (int j = 0; j < iterateAmount; j++)
			{
				glColor3f(coloursArray[3 * j], coloursArray[3 * j + 1], coloursArray[3 * j + 2]);
				if (currentArrayNumber >= 18)
					glVertex3f(xValues[currentArrayNumber - 18], yValues[currentArrayNumber - 18], (zValues[currentArrayNumber - 18]) * -1);
				else
					glVertex3f(xValues[currentArrayNumber], yValues[currentArrayNumber], zValues[currentArrayNumber]);
					
				currentArrayNumber++;
			}
		glEnd();
	}
}

void PentadraPair::rotatePoints(double theta, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis)
{
	// Translate to origin and rotate about axis, then translate back
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
