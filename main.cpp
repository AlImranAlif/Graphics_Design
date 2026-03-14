#include <GL/glut.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    float x_start = -0.8f;  // starting x coordinate for chessboard
    float y_start = 0.8f;   // starting y coordinate for chessboard
    float size = 0.4f;      // size of each square

    // Draw all black squares first
    glColor3f(0.0f, 0.0f, 0.0f); // Black color
    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            if ((row + col) % 2 == 0) // black squares position
            {
                float x = x_start + col * size;
                float y = y_start - row * size;

                glBegin(GL_QUADS);
                    glVertex2f(x, y);
                    glVertex2f(x + size, y);
                    glVertex2f(x + size, y - size);
                    glVertex2f(x, y - size);
                glEnd();
            }
        }
    }

    // Draw all white squares next
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    for (int row = 0; row < 4; ++row)
    {
        for (int col = 0; col < 4; ++col)
        {
            if ((row + col) % 2 != 0) // white squares position
            {
                float x = x_start + col * size;
                float y = y_start - row * size;

                glBegin(GL_QUADS);
                    glVertex2f(x, y);
                    glVertex2f(x + size, y);
                    glVertex2f(x + size, y - size);
                    glVertex2f(x, y - size);
                glEnd();
            }
        }
    }

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // white background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("4x4 Chessboard - Separate Colors");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
