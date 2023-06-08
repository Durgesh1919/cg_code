// #include <GL/glut.h>
// #include <iostream>
// using namespace std;

// int width = 800;
// int height = 600;

// float x1, y1, x2, y2;
// bool isDrawing = false;

// void init(){
//     glClearColor(0.0, 0.0, 0.0, 0.0);
//     glMatrixMode(GL_PROJECTION);
//     gluOrtho2D(0, width, 0, height);
// }

// void setPixel(float x, float y){
//     glBegin(GL_POINTS);
//     glVertex2f(x, y);
//     glEnd();
//     glFlush();
// }

// void drawLineDDA(float x1, float y1, float x2, float y2){
//     float dx = x2 - x1;
//     float dy = y2 - y1;
//     float steps = max(abs(dx), abs(dy));
//     float xIncrement = dx / steps;
//     float yIncrement = dy / steps;
//     float x = x1;
//     float y = y1;

//     for (int i = 0; i <= steps; i++){
//         setPixel(x, y);
//         x += xIncrement;
//         y += yIncrement;
//     }
// }

// void mouseClick(int button, int state, int mouseX, int mouseY){
//     if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
//         if (!isDrawing){
//             x1 = mouseX;
//             y1 = height - mouseY;
//             isDrawing = true;
//         }
//         else{
//             x2 = mouseX;
//             y2 = height - mouseY;
//             isDrawing = false;
//             glutPostRedisplay();
//         }
//     }
// }

// void display(){
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(1.0, 1.0, 1.0);
//     if (isDrawing){
//         glBegin(GL_POINTS);
//         glVertex2f(x1, height - y1);
//         glVertex2f(glutGet(GLUT_WINDOW_WIDTH) - 1, glutGet(GLUT_WINDOW_HEIGHT) - 1);
//         glEnd();
//     }
//     else{
//         drawLineDDA(x1, y1, x2, y2);
//     }

//     glFlush();
// }

// int main(int argc, char** argv){
//     glutInit(&argc, argv);
//     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//     glutInitWindowSize(width, height);
//     glutCreateWindow("DDA Line Drawing Algorithm");
//     init();
//     glutDisplayFunc(display);
//     glutMouseFunc(mouseClick);
//     glutMainLoop();
// }


#include <GL/glut.h>
#include <algorithm>
using namespace std;
int width = 800;
int height = 600;

float x1, y1, x2, y2;
bool isDrawing = false;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, width, 0, height);
}

void setPixel(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

void drawLineDDA(float x1, float y1, float x2, float y2) {
    float dx = x2 - x1;
    float dy = y2 - y1;
    float steps = max(abs(dx), abs(dy));
    float xIncrement = dx / steps;
    float yIncrement = dy / steps;
    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++) {
        setPixel(x, y);
        x += xIncrement;
        y += yIncrement;
    }
}

void mouseClick(int button, int state, int mouseX, int mouseY) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if (!isDrawing) {
            x1 = mouseX;
            y1 = height - mouseY;
            isDrawing = true;
        } else {
            x2 = mouseX;
            y2 = height - mouseY;
            isDrawing = false;
            glutPostRedisplay();
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    if (!isDrawing) {
        drawLineDDA(x1, y1, x2, y2);
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutMainLoop();
}
