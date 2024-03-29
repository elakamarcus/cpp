// Source: https://sudo.tw/article/setup-opengl-for-development-on-cpp
// compile with gcc filename.cpp -o opengltest.out -lGL -lGLU -lglut

#include <GL/glut.h>

void init();
void display();

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(800, 600);

    glutCreateWindow("OpenGL test .. ");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(-5, 5, -5, 5, 5, 15);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0, 0);
    glutWireTeapot(3);

    glFlush();
}