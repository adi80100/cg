#include <iostream>
#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set clear color to white
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500); // Set the orthographic projection
}

void display() {
    float x1 = 100, y1 = 100, x2 = 400, y2 = 300; // Line coordinates
    float dx = x2 - x1, dy = y2 - y1;
    float m, x, y, p;

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0); // Set drawing color to black

    // Calculate slope (m)
    if (dx == 0) {
        m = dy;
    } else {
        m = dy / dx;
    }

    p = 2 * dy - dx;
    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glVertex2i(x, y);

    while (x < x2) {
        x = x + 1;

        if (p >= 0) {
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        } else {
            y = y;
            p = p + 2 * dy;
        }

        glVertex2i(x, y);
    }

    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(450, 100);
    glutCreateWindow("Bresenham Line Drawing");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

