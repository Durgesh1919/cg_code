#include<GL/glut.h>

void display(){
	// glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);

		//TRIANGLE
		glColor3f(1,0,0);glVertex3f(-0.5,0,0);
		glColor3f(1,0,0);glVertex3f(0,0.5,0);
		glColor3f(1,0,0);glVertex3f(0.5,0,0);

		//SQUARE
		glColor3f(0,0,1);glVertex3f(-0.5,0,0);
		glColor3f(0,0,1);glVertex3f(-0.5,-0.5,0);
		glColor3f(0,0,1);glVertex3f(0.5,-0.5,0);
		glColor3f(0,0,1);glVertex3f(0.5,0,0);
	glEnd();
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(80,80);
	glutInitWindowSize(1080,640);
	glutCreateWindow("A Simple Triangle");
	glutDisplayFunc(display);
	glutMainLoop();
}