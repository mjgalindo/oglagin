#include <iostream>
#include <chrono>


#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    uint32_t width = 800, height = 600;

    GLFWwindow *window = glfwCreateWindow(width, height, "Learning", NULL, NULL);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    uint64_t frames = 0;
    auto start = std::chrono::steady_clock::now();

    while (!glfwWindowShouldClose(window))
    {
        auto frameStart = std::chrono::steady_clock::now();
        {
            processInput(window);
            // Rendering ....
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            // Check and swap buffers
            glfwPollEvents();
            glfwSwapBuffers(window);
        }
        frames++;
        auto frameEnd = std::chrono::steady_clock::now();
        auto frameDuration = std::chrono::duration_cast<std::chrono::milliseconds>(frameEnd - frameStart).count();
        std::cout << frames << " frames. Frame duration: " << frameDuration << "ms             \r";
    }
    glfwTerminate();
    return 0;
}