#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <unistd.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float clearColorR = 0.0f;
float clearColorG = 0.0f;
float clearColorB = 0.0f;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 设置背景颜色
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        sleep(1);
        // 清除颜色缓冲区
//        glClear(GL_COLOR_BUFFER_BIT);

        // input
        processInput(window);

        // 在这里进行渲染，或者执行其他操作

        // 更新背景颜色，让颜色渐变
        clearColorR += 0.01f;
        if (clearColorR > 1.0f) {
            clearColorR = 0.0f;
        }
        clearColorG += 0.005f;
        if (clearColorG > 1.0f) {
            clearColorG = 0.0f;
        }
        clearColorB += 0.002f;
        if (clearColorB > 1.0f) {
            clearColorB = 0.0f;
        }

        // 设置新的清除颜色
//        glClearColor(clearColorR, clearColorG, clearColorB, 1.0f);

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // 交换前后缓冲区
        glfwSwapBuffers(window);
        // 处理输入等其他逻辑
        glfwPollEvents();
    }

    std::cout << "window closed" << std::endl;
    // glfw: terminate, clearing all previously allocated GLFW resources.
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
