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
			
		glBegin(GL_LINE_LOOP);
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
	 
	/*glColor3f(1, 0, 0);
	
	// Draw pentadra red flavour face 1

	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[0], yValues[0], zValues[0]);
		glVertex3f(xValues[1], yValues[1], zValues[1]);
		glVertex3f(xValues[2], yValues[2], zValues[2]);
		glVertex3f(xValues[3], yValues[3], zValues[3]);
	glEnd();
	
	// Draw pentadra red flavour face 2
	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[4], yValues[4], zValues[4]);
		glVertex3f(xValues[5], yValues[5], zValues[5]);
		glVertex3f(xValues[6], yValues[6], zValues[6]);
		glVertex3f(xValues[7], yValues[7], zValues[7]);
	glEnd();
	
	// Draw pentadra red flavour face 3
	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[8], yValues[8], zValues[8]);
		glVertex3f(xValues[9], yValues[9], zValues[9]);
		glVertex3f(xValues[10], yValues[10], zValues[10]);
	glEnd(); 
	
	// Draw pentadra red flavour face 4
	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[11], yValues[11], zValues[11]);
		glVertex3f(xValues[12], yValues[12], zValues[12]);
		glVertex3f(xValues[13], yValues[13], zValues[13]);
		glVertex3f(xValues[14], yValues[14], zValues[14]);
	glEnd();
	
	// Draw pentadra red flavour face 5
	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[15], yValues[15], zValues[15]);
		glVertex3f(xValues[16], yValues[16], zValues[16]);
		glVertex3f(xValues[17], yValues[17], zValues[17]);
	glEnd();
	
	glColor3f(0, 1, 0);
	
	// Draw pentadra green flavour face 1
	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[0], yValues[0], -1 * zValues[0]);
		glVertex3f(xValues[1], yValues[1], -1 * zValues[1]);
		glVertex3f(xValues[2], yValues[2], -1 * zValues[2]);
		glVertex3f(xValues[3], yValues[3], -1 * zValues[3]);
	glEnd();
	
	// Draw pentadra green flavour face 2
	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[4], yValues[4], -1 * zValues[4]);
		glVertex3f(xValues[5], yValues[5], -1 * zValues[5]);
		glVertex3f(xValues[6], yValues[6], -1 * zValues[6]);
		glVertex3f(xValues[7], yValues[7], -1 * zValues[7]);
	glEnd();
	
	// Draw pentadra green flavour face 3
	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[8], yValues[8], -1 * zValues[8]);
		glVertex3f(xValues[9], yValues[9], -1 * zValues[9]);
		glVertex3f(xValues[10], yValues[10], -1 * zValues[10]);
	glEnd(); 
	
	// Draw pentadra green flavour face 4
	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[11], yValues[11], -1 * zValues[11]);
		glVertex3f(xValues[12], yValues[12], -1 * zValues[12]);
		glVertex3f(xValues[13], yValues[13], -1 * zValues[13]);
		glVertex3f(xValues[14], yValues[14], -1 * zValues[14]);
	glEnd();
	
	// Draw pentadra green flavour face 5
	glBegin(GL_LINE_LOOP);
		glVertex3f(xValues[15], yValues[15], -1 * zValues[15]);
		glVertex3f(xValues[16], yValues[16], -1 * zValues[16]);
		glVertex3f(xValues[17], yValues[17], -1 * zValues[17]);
	glEnd();*/
}

double PentadraPair::getOriginXValue()
{
	return xOriginValue;
}

double PentadraPair::getOriginYValue()
{
	return yOriginValue;
}

double PentadraPair::getOriginZValue()
{
	return zOriginValue;
}

void PentadraPair::rotatePoints(double theta, GLfloat xAxis, GLfloat yAxis, GLfloat zAxis)
{
	glTranslatef(getOriginXValue(), getOriginYValue(), getOriginZValue());
	glRotatef(theta, xAxis, yAxis, zAxis);
	glTranslatef(getOriginXValue() * -1, getOriginYValue() * -1, getOriginZValue() * -1);
}
