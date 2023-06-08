#include <GL/glut.h>
void myInit(void){
        glClearColor(1.0,1.0,1.0,0.0);
        glColor3f(0.0f,0.0f,0.0f);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0,640.0,0.0,480.0);
}

void myDisplay(void){
        glClear (GL_COLOR_BUFFER_BIT);
        glClearColor(0.0,0.0,0.2,1);
        glPointSize(5.0);
        glBegin(GL_POLYGON);
                glColor3f(1.0f,0.0f,0.0f);
                glVertex2f(-0.5,-0.5);
                glColor3f(0.0f,1.0f,0.0f);
                glVertex2f(0.5,-0.5);
                glColor3f(0.0f,0.0f,1.0f);
                glVertex2f(0.5,0.25);
                glColor3f(1.0f,1.0f,0.0f);
                glVertex2f(-0.5,0.25);
        glEnd();

        glBegin(GL_POLYGON);
                glColor3f(1.0f,0.0f,0.0f);
                glVertex2f(-0.5,0.25);
                glColor3f(0.0f,1.0f,0.0f);
                glVertex2f(0.5,0.25);
                glColor3f(1.0f,1.0f,0.0f);
                glVertex2f(0.0,0.9);

        glEnd();
        glFlush();
}

int main (int argc, char** argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(800, 600) ;
        glutInitWindowPosition(50, 50);
        glutCreateWindow("Hello World");
        glutDisplayFunc(myDisplay);

        glutMainLoop();
		return 0;
}