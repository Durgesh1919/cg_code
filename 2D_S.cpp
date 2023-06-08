#include <GL/glut.h>
#include <iostream>

int edge = 4;
int xpoint[] = { -50, 50, 50, -50 };
int ypoint[] = { -50, -50, 50, 50 };

void scale(float sx, float sy) {
    // Scale the point
    for (int i = 0; i < edge; i++) {
        if (sx >= 0)
            xpoint[i] = xpoint[i] * sx;
        else
            xpoint[i] = xpoint[i] / (-sx);
        
        if (sy >= 0)
            ypoint[i] = ypoint[i] * sy;
        else
            ypoint[i] = ypoint[i] / (-sy);
    }

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 1);
    for (int i = 0; i < edge; i++) {
        glVertex2i(xpoint[i], ypoint[i]);
    }
    glEnd();
    glFlush();
}

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

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 's':
    case 'S':
        float sx, sy;
        std::cout << "Enter scaling factor on X-axis: ";
        std::cin >> sx;
        std::cout << "Enter scaling factor on Y-axis: ";
        std::cin >> sy;
        scale(sx, sy);
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("2D Scaling");
    gluOrtho2D(-200, 200, -200, 200);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
