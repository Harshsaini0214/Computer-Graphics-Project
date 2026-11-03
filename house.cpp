
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
using namespace std;

void rectangle(float x1,float y1,float x2,float y2,
               float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(x1,y1);
    glVertex2f(x2,y1);
    glVertex2f(x2,y2);
    glVertex2f(x1,y2);
    glEnd();
}

void triangle(float x1,float y1,float x2,float y2,
              float x3,float y3,float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();
}

void circle(float x,float y,float radius,
            float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);

    for(int i=0;i<=100;i++)
    {
        float a=2*3.14159f*i/100;
        glVertex2f(x+radius*cos(a),y+radius*sin(a));
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    rectangle(0,0,800,600,0.5,0.8,1.0);
    circle(680,500,45,1,1,0);
    rectangle(0,0,800,180,0.1,0.6,0.2);
    rectangle(200,180,600,430,1.0,0.8,0.4);
    triangle(160,430,640,430,400,570,0.7,0.1,0.1);
    rectangle(500,480,550,580,0.5,0.2,0.1);
    rectangle(350,180,450,340,0.4,0.2,0.1);
    circle(435,260,5,1,1,0);
    rectangle(230,300,320,380,0.2,0.7,1);
    rectangle(480,300,570,380,0.2,0.7,1);
    rectangle(270,300,275,380,1,1,1);

    rectangle(230,335,320,340,1,1,1);
    rectangle(520,300,525,380,1,1,1);
    rectangle(480,335,570,340,1,1,1);

    triangle(350,180,450,180,520,0,0.6,0.6,0.6);
    triangle(350,180,520,0,280,0,0.6,0.6,0.6);

    rectangle(80,180,105,300,0.4,0.2,0.1);
    circle(92,330,55,0.0,0.5,0.1);

    rectangle(690,180,715,300,0.4,0.2,0.1);
    circle(702,330,55,0.0,0.5,0.1);

    glFlush();
}

int main()
{
    if(!glfwInit()) return -1;

    GLFWwindow* w=glfwCreateWindow(
        800,600,"2D House using OpenGL",NULL,NULL);

    if(!w)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(w);

    glClearColor(0.5,0.8,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,800,0,600,-1,1);

    while(!glfwWindowShouldClose(w))
    {
        display();
        glfwSwapBuffers(w);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
