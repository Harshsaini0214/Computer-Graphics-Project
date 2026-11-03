
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <cmath>

const int WIDTH = 1000;
const int HEIGHT = 700;

const double RED_TIME = 5.0;
const double GREEN_TIME = 5.0;
const double YELLOW_TIME = 2.0;
const double TOTAL_TIME = RED_TIME + GREEN_TIME + YELLOW_TIME;

bool paused = false;
double pauseStart = 0.0;
double pausedDuration = 0.0;

void drawRectangle(float x1, float y1,
                   float x2, float y2,
                   float r, float g, float b)
{
    glColor3f(r, g, b);

    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void drawCircle(float cx, float cy, float radius,
                float r, float g, float b)
{
    glColor3f(r, g, b);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(cx, cy);

        for (int i = 0; i <= 100; i++)
        {
            float angle = 2.0f * 3.14159265f * i / 100;

            float x = cx + radius * cos(angle);
            float y = cy + radius * sin(angle);

            glVertex2f(x, y);
        }

    glEnd();
}

void drawBackground()
{

    drawRectangle(-1.0f, 0.0f, 1.0f, 1.0f,
                  0.53f, 0.81f, 0.92f);


    drawRectangle(-1.0f, -1.0f, 1.0f, 0.0f,
                  0.25f, 0.65f, 0.25f);


    drawRectangle(-1.0f, -0.55f, 1.0f, -0.05f,
                  0.20f, 0.20f, 0.20f);


    drawRectangle(-1.0f, -0.32f, 1.0f, -0.30f,
                  1.0f, 1.0f, 1.0f);


    for (int i = 0; i < 7; i++)
    {
        float x = -0.9f + i * 0.12f;

        drawRectangle(x, -0.05f, x + 0.06f, 0.0f,
                      1.0f, 1.0f, 1.0f);
    }
}

void drawTrafficSignal()
{

    drawRectangle(-0.08f, -0.75f, 0.0f, 0.35f,
                  0.35f, 0.35f, 0.35f);

    drawRectangle(-0.25f, 0.25f, 0.17f, 0.95f,
                  0.08f, 0.08f, 0.08f);

    drawRectangle(-0.28f, 0.22f, 0.20f, 0.98f,
                  0.4f, 0.4f, 0.4f);


    drawRectangle(-0.25f, 0.25f, 0.17f, 0.95f,
                  0.08f, 0.08f, 0.08f);
}

int getSignal(double elapsed)
{
    double t = fmod(elapsed, TOTAL_TIME);

    if (t < RED_TIME)
        return 0; 

    if (t < RED_TIME + GREEN_TIME)
        return 1; 

    return 2;     
}

void drawLights(int activeSignal)
{

    if (activeSignal == 0)
        drawCircle(-0.04f, 0.82f, 0.105f, 1.0f, 0.0f, 0.0f);
    else
        drawCircle(-0.04f, 0.82f, 0.105f, 0.25f, 0.02f, 0.02f);


    if (activeSignal == 2)
        drawCircle(-0.04f, 0.60f, 0.105f, 1.0f, 0.85f, 0.0f);
    else
        drawCircle(-0.04f, 0.60f, 0.105f, 0.25f, 0.20f, 0.02f);


    if (activeSignal == 1)
        drawCircle(-0.04f, 0.38f, 0.105f, 0.0f, 1.0f, 0.0f);
    else
        drawCircle(-0.04f, 0.38f, 0.105f, 0.02f, 0.25f, 0.02f);
}

// Keyboard controls
void keyCallback(GLFWwindow* window, int key,
                 int scancode, int action, int mods)
{
    if (action != GLFW_PRESS)
        return;

    if (key == GLFW_KEY_ESCAPE)
        glfwSetWindowShouldClose(window, true);

    if (key == GLFW_KEY_SPACE)
    {
        if (!paused)
        {
            paused = true;
            pauseStart = glfwGetTime();
        }
        else
        {
            paused = false;
            pausedDuration += glfwGetTime() - pauseStart;
        }
    }
}

// Display simulation information in terminal
void printSignalInfo(int signal, int remaining)
{
    static int previousSignal = -1;

    if (signal != previousSignal)
    {
        previousSignal = signal;

        if (signal == 0)
            std::cout << "\nRED LIGHT - STOP\n";

        else if (signal == 1)
            std::cout << "\nGREEN LIGHT - GO\n";

        else
            std::cout << "\nYELLOW LIGHT - WAIT\n";
    }
}

// Main function
int main()
{
    if (!glfwInit())
    {
        std::cout << "GLFW initialization failed!\n";
        return -1;
    }

    // Request compatibility OpenGL context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    GLFWwindow* window = glfwCreateWindow(
        WIDTH, HEIGHT,
        "Traffic Light Simulation - OpenGL",
        NULL, NULL
    );

    if (!window)
    {
        std::cout << "Window creation failed!\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keyCallback);

    // Enable V-Sync
    glfwSwapInterval(1);

    // Setup 2D projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    std::cout << "TRAFFIC LIGHT SIMULATION STARTED\n";
    std::cout << "SPACE = Pause / Resume\n";
    std::cout << "ESC = Exit\n";

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        double currentTime = paused ? pauseStart : glfwGetTime();

        double elapsed = currentTime - pausedDuration;

        int signal = getSignal(elapsed);

        double cycleTime = fmod(elapsed, TOTAL_TIME);

        int remaining;

        if (cycleTime < RED_TIME)
            remaining = (int)ceil(RED_TIME - cycleTime);
        else if (cycleTime < RED_TIME + GREEN_TIME)
            remaining = (int)ceil(RED_TIME + GREEN_TIME - cycleTime);
        else
            remaining = (int)ceil(TOTAL_TIME - cycleTime);

        // Draw scene
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        drawBackground();
        drawTrafficSignal();
        drawLights(signal);

        printSignalInfo(signal, remaining);

        // Update window title with signal information
        std::string status;

        if (signal == 0)
            status = "RED - STOP";
        else if (signal == 1)
            status = "GREEN - GO";
        else
            status = "YELLOW - WAIT";

        std::string title =
            "Traffic Light | " + status +
            " | Time: " + std::to_string(remaining) +
            (paused ? " | PAUSED" : "");

        glfwSetWindowTitle(window, title.c_str());

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    std::cout << "\nSimulation closed successfully!\n";

    return 0;
}
