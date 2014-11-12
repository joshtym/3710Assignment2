#ifndef PENTADRAPAIR_H
#define PENTADRAPAIR_H

#include <GL/glut.h>

class PentadraPair
{
	public:
		PentadraPair();
		PentadraPair(double, double, double);
		~PentadraPair();
		void drawPentadraPair();
		double getOriginXValue();
		double getOriginYValue();
		double getOriginZValue();
		void rotatePoints(double, GLfloat, GLfloat, GLfloat);
		
	private:
		double xValues[18] = {0, 0, 0.5, 0.75, 0.5, 0.25, 0, 0, 0.25, 0.5, 0, 0.25, 0.5, 0.75, 0.5, 0.5, 0, 0.75};
		double yValues[18] = {0, 0, 0, 0, 0.5, 0.25, 0, 0, 0.25, 0, 0, 0.25, 0.5, 0, 0, 0.5, 0, 0};
		double zValues[18] = {0, -1, -1, -0.75, -0.5, -1, -1, 0, -1, -1, -1, -1, -0.5, -0.75, -1, -0.5, 0, -0.75};
		double colourOne[3] = {1, 0, 0};
		double colourTwo[3] = {0, 1, 0};
		double PI = 3.14159265;
		double xOriginValue;
		double yOriginValue;
		double zOriginValue;
};

#endif
