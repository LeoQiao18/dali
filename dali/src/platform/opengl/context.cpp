//
// Created by Leo on 5/16/2020.
//

#include <dali/core.h>

#include <dali/platform/opengl/context.h>

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace dali {
    OpenGLContext::OpenGLContext(GLFWwindow *window)
            : m_window(window) {
        DALI_CORE_ASSERT(window, "Window handle is null");
    }

    void OpenGLContext::init() {
        glfwMakeContextCurrent(m_window);
        int status = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        DALI_CORE_ASSERT(status, "Failed to initialize");

        DALI_CORE_INFO("Initialized OpenGL:");
        DALI_CORE_INFO("  > Vendor: {0}", glGetString(GL_VENDOR));
        DALI_CORE_INFO("  > Renderer: {0}", glGetString(GL_RENDERER));
        DALI_CORE_INFO("  > Version: {0}", glGetString(GL_VERSION));
    }

    void OpenGLContext::swap_buffers() {
        glfwSwapBuffers(m_window);
    }
}
