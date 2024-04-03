#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Potential Energy using OpenGL with GLEW and GLFW", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_LINES);
        // Draw X and Y axis
        glColor3f(1.0, 1.0, 1.0);
        // X-axis
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
        // Y-axis
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
        glEnd();

        glBegin(GL_POINTS);
        glColor3f(0.0, 1.0, 0.0);

        // variable to plot potential energy
        float m = 0.1;    // mass (kg)
        float g = 9.8;    // acceleration due to gravity (m/s^2)

        for (float height = 0; height <= 1.0; height += 0.001)      // varying the height of a mass above ground from 0 to 1 meter
        {
            float PE = m * g * height;    // potential energy (joules)
            glVertex2f(height, PE);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}