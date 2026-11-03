
#include <GLFW/glfw3.h>
#include <iostream>
using namespace std;

float angle = 0;

void drawCube()
{
    glBegin(GL_QUADS);

    glColor3f(0.0,0.7,1.0);
    glVertex3f(-1.3,-1.3,1.3);
    glVertex3f(1.3,-1.3,1.3);
    glVertex3f(1.3,1.3,1.3);
    glVertex3f(-1.3,1.3,1.3);

    glColor3f(0.0,0.3,0.7);
    glVertex3f(-1.3,-1.3,-1.3);
    glVertex3f(-1.3,1.3,-1.3);
    glVertex3f(1.3,1.3,-1.3);
    glVertex3f(1.3,-1.3,-1.3);

    glColor3f(0.2,0.9,1.0);
    glVertex3f(-1.3,1.3,-1.3);
    glVertex3f(-1.3,1.3,1.3);
    glVertex3f(1.3,1.3,1.3);
    glVertex3f(1.3,1.3,-1.3);

    glColor3f(0.0,0.2,0.5);
    glVertex3f(-1.3,-1.3,-1.3);
    glVertex3f(1.3,-1.3,-1.3);
    glVertex3f(1.3,-1.3,1.3);
    glVertex3f(-1.3,-1.3,1.3);

    glColor3f(0.0,0.5,0.9);
    glVertex3f(1.3,-1.3,-1.3);
    glVertex3f(1.3,1.3,-1.3);
    glVertex3f(1.3,1.3,1.3);
    glVertex3f(1.3,-1.3,1.3);


    glColor3f(0.1,0.6,0.8);
    glVertex3f(-1.3,-1.3,-1.3);
    glVertex3f(-1.3,-1.3,1.3);
    glVertex3f(-1.3,1.3,1.3);
    glVertex3f(-1.3,1.3,-1.3);

    glEnd();

    glColor3f(0.7,0.95,1.0);
    glLineWidth(2.5);

    float v[8][3] = {
        {-1.3,-1.3,-1.3},{1.3,-1.3,-1.3},
        {1.3,1.3,-1.3},{-1.3,1.3,-1.3},
        {-1.3,-1.3,1.3},{1.3,-1.3,1.3},
        {1.3,1.3,1.3},{-1.3,1.3,1.3}
    };

    int e[12][2] = {
        {0,1},{1,2},{2,3},{3,0},
        {4,5},{5,6},{6,7},{7,4},
        {0,4},{1,5},{2,6},{3,7}
    };

    glBegin(GL_LINES);
    for(int i=0;i<12;i++)
    {
        glVertex3fv(v[e[i][0]]);
        glVertex3fv(v[e[i][1]]);
    }
    glEnd();
}

int main()
{
    if(!glfwInit()) return -1;

    GLFWwindow* w = glfwCreateWindow(
        900,700,"Beautiful 3D Cube",NULL,NULL);

    if(!w)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(w);
    glEnable(GL_DEPTH_TEST);

    glClearColor(0.0,0.0,0.0,1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.15,1.15,-0.9,0.9,1,100);

    glMatrixMode(GL_MODELVIEW);

    while(!glfwWindowShouldClose(w))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glLoadIdentity();
        glTranslatef(0,0,-7);

        glRotatef(25,1,0,0);
        glRotatef(angle,0,1,0);

        drawCube();

        angle += 0.12f;

        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
