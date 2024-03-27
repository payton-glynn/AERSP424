//#include <GL/glew.h>
//#include <GLFW/glfw3.h>
//#include <cmath>
//#include <iostream>
//
//int main() {
//  if ( !glfwInit() ) {
//    std::cerr << "Failed to initialize GLFW" << std::endl;
//    return -1;
//  }
//
//  GLFWwindow* window = glfwCreateWindow( 500, 500, "Sine Curve using OpenGL with GLEW and GLFW", NULL, NULL );
//  if ( !window ) {
//    std::cerr << "Failed to create GLFW window" << std::endl;
//    glfwTerminate();
//    return -1;
//  }
//
//  glfwMakeContextCurrent( window );
//
//  if ( glewInit() != GLEW_OK ) {
//    std::cerr << "Failed to initialize GLEW" << std::endl;
//    return -1;
//  }
//
//  glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
//
//  while ( !glfwWindowShouldClose( window ) ) {
//    glClear( GL_COLOR_BUFFER_BIT );
//
//    glBegin( GL_LINES );
//    // Draw X and Y axis
//    glColor3f( 1.0, 1.0, 1.0 );
//    glVertex2f( -1.0, 0.0 );
//    glVertex2f( 1.0, 0.0 );
//    glVertex2f( 0.0, 1.0 );
//    glVertex2f( 0.0, -1.0 );
//
//    // Plot sine curve
//    glColor3f( 0.0, 1.0, 0.0 );
//    for ( float i = 0; i < 2 * 3.14159; i += 0.001 ) {
//      float x = ( 2 * i - 3.14159 ) / 3.14159;
//      float y = sin( i );
//      glVertex2f( x, y - 0.001 );
//      glVertex2f( x, y );
//    }
//    //float rho = 1.225;  // density of air (kg/m^3)
//    //float c = 8;    // chord of aircraft (m)
//    //float mu = 0.00001825;  // dynamic viscosity (kg/(m*s))
//
//    glBegin(GL_LINE_STRIP);     // use GL_LINE_STRIP to connect the points
//
//    //for (float velocity = 0; velocity <= 300; velocity += 0.01)
//    //{
//    //    float Reynolds = (rho * velocity * c) / mu;           // Reynold's #
//    //    glColor3f(0.0, 0.0, 1.0);           // Blue color for Reynolds number
//    //    glVertex2f(velocity / 300, Reynolds / 300);       // Normalize coordinates to fit within [-1, 1] range
//    //}
//    glEnd();
//
//    glfwSwapBuffers( window );
//    glfwPollEvents();
//  }
//
//  glfwTerminate();
//  return 0;
//}



#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(500, 500, "Parabola using OpenGL with GLEW and GLFW", NULL, NULL);
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
        glVertex2f(0.0, -1);
        glVertex2f(0.0, 1);
        glEnd();

        glBegin(GL_POINTS);
        // Plot parabola
        glColor3f(0.0, 1.0, 0.0);

      float rho = 1.225;  // density of air (kg/m^3)
      float c = 1.5;    // chord of aircraft (m) (I used a cessna 172 chord)
      float mu = 0.00001825;  // dynamic viscosity (kg/(m*s))

        for (float x = -1.0; x <= 1.0; x += 0.001) 
        {
            float y = (rho * x * c)/mu;
            glVertex2f(x, y);
        }
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


