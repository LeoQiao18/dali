//
// Created by Leo on 5/16/2020.
//

#ifndef __DALI_PLATFORM_OPENGL_CONTEXT_H
#define __DALI_PLATFORM_OPENGL_CONTEXT_H

#include <dali/renderer/context.h>

struct GLFWwindow;

namespace dali {
    class OpenGLContext : public GraphicsContext {
    public:
        OpenGLContext(GLFWwindow *window);

        virtual void init() override;

        virtual void swap_buffers() override;

    private:
        GLFWwindow *m_window;
    };
}

#endif //__DALI_PLATFORM_OPENGL_CONTEXT_H
