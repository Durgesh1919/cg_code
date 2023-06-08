#include <GL/glut.h>
#include <iostream>

int edge = 4;
int xpoint[] = { -50, 50, 50, -50 };
int ypoint[] = { -50, -50, 50, 50 };

using namespace std;

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glColor3f(0, 0, 1);
        for (int i = 0; i < edge; i++) {
            glVertex2i(xpoint[i], ypoint[i]);
        }
    glEnd();
    glFlush();
}

void translation(int tx, int ty) {
    // Translate the point
    for (int i = 0; i < edge; i++) {
        xpoint[i] = xpoint[i] + tx;
        ypoint[i] = ypoint[i] + ty;
    }

   display();
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 't':
    case 'T':
        int tx, ty;
        cout << "Enter Tx, Ty: ";
        cin >> tx >> ty;
        translation(tx, ty);
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("2D Translation");
    gluOrtho2D(-200, 200, -200, 200);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
