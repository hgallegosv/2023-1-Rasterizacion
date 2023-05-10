#include <iostream>

#include <GL/freeglut.h>

void SampleKeyboard( unsigned char cChar, int nMouseX, int nMouseY ) {
    switch (cChar) {
        case 'f':
        case 'F':
            printf("main window toggle fullscreen\n");
            glutFullScreenToggle();

            break;
    }
}

void Redisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_QUADS);
    /* face +Z */
    glNormal3f(0, 0, 1);
    glColor3f(1, 0, 0);
    glVertex3f(-1, -1, 0);
    glVertex3f(0, -1, 0);
    glVertex3f(0, 1, 0);
    glVertex3f(-1, 0, 0);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, _argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(400, 300);

    int nWindow = glutCreateWindow("test");

    glutKeyboardFunc( SampleKeyboard );
    glutDisplayFunc( Redisplay );
    glutMainLoop();
    return 0;
}
