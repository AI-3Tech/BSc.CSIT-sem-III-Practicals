//wap to draw a line using OpenGL and Glut utility tool.
#include<GL/glut.h>
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 399.9, 0.0, 399.9);
}

void lineSegment(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.4, 0.2);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2i(50, 50);
		glVertex2i(300, 300);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Drawing a line");
	myinit();
	glutDisplayFunc(lineSegment);
	glutMainLoop();
	return 0;
}