#include <GL/glut.h>
#include <cmath>
#include <iostream>
#include "PentadraPair.h"

PentadraPair::PentadraPair()
{
	double xValues[] = {0, 0, 0.5, 0.75, 0.5, 0.25, 0, 0, 0.25, 0.5, 0, 0.25, 0.5, 0.75, 0.5, 0.5, 0, 0.75};
	double yValues[] = {0, 0, 0, 0, 0.5, 0.25, 0, 0, 0.25, 0, 0, 0.25, 0.5, 0, 0, 0.5, 0, 0};
	double zValues[] = {0, -1, -1, -0.75, -0.5, -1, -1, 0, -1, -1, -1, -1, -0.5, -0.75, -1, -0.5, 0, -0.75};
	
	double colourOne[] = {1, 0, 0};
	double colourTwo[] = {0, 1, 0};
	
	xOriginValue = 0;
	yOriginValue = 0;
	zOriginValue = 0;
	
}

PentadraPair::PentadraPair(double xyAlteration, double zAlteration)
{
	for (int i = 0; i < 18; i++)
	{
		xValues[i] = xValues[i] + cos(xyAlteration * PI / 180);
		yValues[i] = yValues[i] + sin(xyAlteration * PI / 180);
		zValues[i] = zValues[i] + zAlteration;
	}
	
	xOriginValue = xValues[0];
	yOriginValue = yValues[0];
	zOriginValue = zValues[0];
}

PentadraPair::~PentadraPair()
{
}

void PentadraPair::drawPentadraPair()
{
	/*int iterateAmount = 0;
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
				//std::cout << xValues[currentArrayNumber] << std::endl;
				glColor3f(1, 0, 0);
				if (currentArrayNumber >= 18)
					glVertex3f(xValues[currentArrayNumber - 18], yValues[currentArrayNumber - 18], (zValues[currentArrayNumber - 18]) * -1);
				else
					glVertex3f(xValues[currentArrayNumber], yValues[currentArrayNumber], zValues[currentArrayNumber]);
					
				currentArrayNumber++;
			}
		glEnd();
	}*/
	 
	glColor3f(1, 0, 0);
	
	// Draw pentadra red flavour face 1

	glBegin(GL_LINE_LOOP);
		glVertex3f(0.00, 0.00, 0.00);
		glVertex3f(0.00, 0.00, -1.00);
		glVertex3f(0.50, 0.00, -1.00);
		glVertex3f(0.75, 0.00, -0.75);
	glEnd();
	
	// Draw pentadra red flavour face 2
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.50, 0.50, -0.50);
		glVertex3f(0.25, 0.25, -1.00);
		glVertex3f(0.00, 0.00, -1.00);
		glVertex3f(0.00, 0.00, 0.00);
	glEnd();
	
	// Draw pentadra red flavour face 3
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.25, 0.25, -1.00);
		glVertex3f(0.50, 0.00, -1.00);
		glVertex3f(0.00, 0.00, -1.00);
	glEnd(); 
	
	// Draw pentadra red flavour face 4
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.25, 0.25, -1.00);
		glVertex3f(0.50, 0.50, -0.50);
		glVertex3f(0.75, 0.00, -0.75);
		glVertex3f(0.50, 0.00, -1.00);
	glEnd();
	
	// Draw pentadra red flavour face 5
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.50, 0.50, -0.50);
		glVertex3f(0.00, 0.00, 0.00);
		glVertex3f(0.75, 0.00, -0.75);
	glEnd();
	
	glColor3f(0, 1, 0);
	
	// Draw pentadra green flavour face 1
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.00, 0.00, 0.00);
		glVertex3f(0.00, 0.00, 1.00);
		glVertex3f(0.50, 0.00, 1.00);
		glVertex3f(0.75, 0.00, 0.75);
	glEnd();
	
	// Draw pentadra green flavour face 2
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.50, 0.50, 0.50);
		glVertex3f(0.25, 0.25, 1.00);
		glVertex3f(0.00, 0.00, 1.00);
		glVertex3f(0.00, 0.00, 0.00);
	glEnd();
	
	// Draw pentadra green flavour face 3
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.25, 0.25, 1.00);
		glVertex3f(0.50, 0.00, 1.00);
		glVertex3f(0.00, 0.00, 1.00);
	glEnd();
	
	// Draw pentadra green flavour face 4
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.25, 0.25, 1.00);
		glVertex3f(0.50, 0.50, 0.50);
		glVertex3f(0.75, 0.00, 0.75);
		glVertex3f(0.50, 0.00, 1.00);
	glEnd();
	
	// Draw pentadra green flavour face 5
	glBegin(GL_LINE_LOOP);
		glVertex3f(0.50, 0.50, 0.50);
		glVertex3f(0.00, 0.00, 0.00);
		glVertex3f(0.75, 0.00, 0.75);
	glEnd();
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
	//glTranslatef(getOriginXValue(), getOriginYValue(), getOriginZValue());
	glRotatef(theta, xAxis, yAxis, zAxis);
	//glTranslatef(getOriginXValue() * -1, getOriginYValue() * -1, getOriginZValue() * -1);
}
