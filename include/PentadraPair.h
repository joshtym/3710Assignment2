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
		double xValues[18];
		double yValues[18];
		double zValues[18];
		double colourOne[3];
		double colourTwo[3];
		double PI = 3.14159265;
		double xOriginValue;
		double yOriginValue;
		double zOriginValue;
};

#endif
