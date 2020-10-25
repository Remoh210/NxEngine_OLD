#include "GLFWPlatformWindow.h"
#define LOG_TYPE_WINDOW "Window"

//Camera* GLFWPlatformWindow::MainCamera;

std::function<void (int, int)> GLFWPlatformWindow::MouseCallbackFunc = [](int, int){};
std::function<void (int, int)> GLFWPlatformWindow::FrameBufferResizeCallbackBackFunc = [](int, int){};

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void GLFWPlatformWindow::GLFWMouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	GLFWPlatformWindow::MouseCallbackFunc(xpos, ypos);
}

void GLFWPlatformWindow::GLFWFrameBufferResizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    FrameBufferResizeCallbackBackFunc(width, height);
}

GLFWPlatformWindow::GLFWPlatformWindow(uint32 width, uint32 height, const char* title)
	:mWidth(width),
	mHeight(height)
{
    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == NULL)
    {
        DEBUG_LOG(LOG_TYPE_WINDOW, LOG_ERROR, "Failed to create GLFW window");
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, GLFWPlatformWindow::GLFWMouseCallback);
    gladLoadGL(glfwGetProcAddress);
}

void GLFWPlatformWindow::Resize(int width, int height)
{
    
}

void GLFWPlatformWindow::Present()
{
    glfwSwapBuffers(window);
}




