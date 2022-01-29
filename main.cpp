#include "Grid/Grid.h"


static void reshapeFunc(int w, int h);
static void displayFunc();
static void keyboardFunc(unsigned char key, int, int);

Grid    grid;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("GLUT_3D_Grid");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    if (argv[1] != nullptr) {
        if (grid.readFile(argv[1]) == 1) {
            return 1;
        }
    }
    else {
        return 1;
    }

    glClearColor(0.1, 0.1, 0.1, 1);

    glutReshapeFunc(reshapeFunc);
    glutDisplayFunc(displayFunc);
    glutKeyboardFunc(keyboardFunc);

    glutMainLoop();

    return 0;
}

static void reshapeFunc(int w, int h) {
    GLfloat aspect = (GLfloat)w / (GLfloat)h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 1000.0f);
}

static void displayFunc() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    grid.onRender();

    glutSwapBuffers();
}

static void keyboardFunc(unsigned char key, int, int) {
    if (key == 'x') {
        grid.angleX += 5.0f;
    }
    if (key == 'y') {
        grid.angleY += 5.0f;
    }
    if (key == 'z') {
        grid.angleZ += 5.0f;
    }
    if (key == '=') {
        grid.zoom += 0.5f;
    }
    if (key == '-') {
        grid.zoom -= 0.5f;
    }
    if (key == 27) {
        exit(0);
    }
    if (key == 'm') {
        if (grid.outerSurfaces == true) {
            grid.outerSurfaces = false;
        }
        else {
            grid.outerSurfaces = true;
        }
    }
    if (key == 13) {
        if (grid.figure == true) {
            grid.figure = false;
        }
        else {
            grid.figure = true;
        }
    }

    glutPostRedisplay();
}
