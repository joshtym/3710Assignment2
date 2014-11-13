#ifndef PENTADRAPAIR_H
#define PENTADRAPAIR_H

#include <GL/glut.h>

class PentadraPair
{
	public:
		PentadraPair();
		PentadraPair(double, double, double);
		~PentadraPair();
		void drawAndRotate(double, GLfloat, GLfloat, GLfloat);
		
	private:
		void drawPentadraPair();
		void rotatePoints(double, GLfloat, GLfloat, GLfloat);
		
		
		double xValues[18] = {0, 0, 0.5, 0.75, 0.5, 0.25, 0, 0, 0.25, 0.5, 0, 0.25, 0.5, 0.75, 0.5, 0.5, 0, 0.75};
		double yValues[18] = {0, 0, 0, 0, 0.5, 0.25, 0, 0, 0.25, 0, 0, 0.25, 0.5, 0, 0, 0.5, 0, 0};
		double zValues[18] = {0, -1, -1, -0.75, -0.5, -1, -1, 0, -1, -1, -1, -1, -0.5, -0.75, -1, -0.5, 0, -0.75};
		double coloursArray[12] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0};
		
		double xOriginValue;
		double yOriginValue;
		double zOriginValue;
};

#endif
