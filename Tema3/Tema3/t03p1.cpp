
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "glut.h"

// dimensiunea ferestrei in pixeli
#define dim 300

unsigned char prevKey;

class GrilaCarteziana {
public:
	int line, column;
	double ratieX, ratieY;

	GrilaCarteziana(int line, int column) {
		this->line = line - 1;
		this->column = column - 1;
		this->ratieX = double(1.8 / this->column);
		this->ratieY = double(1.8 / this->line);
	}

	void deseneaza() {

		glColor3f(0, 0, 0);
		for (double i = -0.9;i <= 0.91;i += ratieX) {
			glBegin(GL_LINE_STRIP);
			glVertex2d(i, 0.9);
			glVertex2d(i, -0.9);
			glEnd();
		}
		for (double i = -0.9;i <= 0.91;i += ratieY) {
			glBegin(GL_LINE_STRIP);
			glVertex2d(0.9, i);
			glVertex2d(-0.9, i);
			glEnd();
		}
	};

	void writePixel(int i, int j) {
		double raza = fmin(ratieX / 3, ratieY / 3);
		if (i<0 || i>this->column || j<0 || j>this->line) {
			return;
		}
		double xPixel = -0.9 + ratieX * j;
		double yPixel = 0.9 - ratieY * i;
		double pi = 4 * atan(1);
		glColor3f(0.3, 0.3, 0.3);
		glPolygonMode(GL_FRONT, GL_FILL);
		glBegin(GL_POLYGON);
		for (int i = 0; i <= 360; i++) {
			double angle = 2 * pi * i / 360;
			double x = cos(angle) * raza;
			double y = sin(angle) * raza;
			glVertex2d(xPixel + x, yPixel + y);
		}
		glEnd();
	};

};



void Display1() {
	GrilaCarteziana gc(16, 16);
	gc.deseneaza();
	gc.writePixel(0, 0);
	gc.writePixel(0, 1);
	gc.writePixel(0, 2);
	gc.writePixel(0, 3);
	gc.writePixel(0, 4);
	gc.writePixel(1, 0);
	gc.writePixel(1, 1);
	gc.writePixel(1, 2);
	gc.writePixel(1, 3);
	gc.writePixel(1, 4);
	gc.writePixel(1, 5);
	gc.writePixel(1, 6);
	gc.writePixel(1, 7);
	gc.writePixel(2, 2);
	gc.writePixel(2, 3);
	gc.writePixel(2, 4);
	gc.writePixel(2, 5);
	gc.writePixel(2, 6);
	gc.writePixel(2, 7);
	gc.writePixel(2, 8);
	gc.writePixel(2, 9);
	gc.writePixel(2, 10);
	gc.writePixel(3, 5);
	gc.writePixel(3, 6);
	gc.writePixel(3, 7);
	gc.writePixel(3, 8);
	gc.writePixel(3, 9);
	gc.writePixel(3, 10);
	gc.writePixel(3, 11);
	gc.writePixel(3, 12);
	gc.writePixel(3, 13);
	gc.writePixel(4, 8);
	gc.writePixel(4, 9);
	gc.writePixel(4, 10);
	gc.writePixel(4, 11);
	gc.writePixel(4, 12);
	gc.writePixel(4, 13);
	gc.writePixel(4, 14);
	gc.writePixel(4, 15);
	gc.writePixel(5, 11);
	gc.writePixel(5, 12);
	gc.writePixel(5, 13);
	gc.writePixel(5, 14);
	gc.writePixel(5, 15);
	gc.writePixel(6, 14);
	gc.writePixel(6, 15);
	gc.writePixel(15, 0);
	gc.writePixel(15, 1);
	gc.writePixel(14, 2);
	gc.writePixel(14, 3);
	gc.writePixel(13, 4);
	gc.writePixel(13, 5);
	gc.writePixel(12, 6);
	gc.writePixel(12, 7);
	gc.writePixel(11, 8);
	gc.writePixel(11, 9);
	gc.writePixel(10, 10);
	gc.writePixel(10, 11);
	gc.writePixel(9, 12);
	gc.writePixel(9, 13);
	gc.writePixel(8, 14);
	gc.writePixel(8, 15);
}

void Init(void) {

	glClearColor(1.0, 1.0, 1.0, 1.0);

	glLineWidth(1);

	//   glPointSize(4);

	glPolygonMode(GL_FRONT, GL_LINE);
}

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	switch (prevKey) {
	case '1':
		Display1();
		break;
	default:
		break;
	}

	glFlush();
}

void Reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
	prevKey = key;
	if (key == 27) // escape
		exit(0);
	glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitWindowSize(dim, dim);

	glutInitWindowPosition(100, 100);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutCreateWindow(argv[0]);

	Init();

	glutReshapeFunc(Reshape);

	glutKeyboardFunc(KeyboardFunc);

	glutMouseFunc(MouseFunc);

	glutDisplayFunc(Display);

	glutMainLoop();

	return 0;
}
