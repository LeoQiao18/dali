//
// Created by Leo on 5/24/2020.
//

#ifndef __DALI_RENDERER_RENDERER_H
#define __DALI_RENDERER_RENDERER_H

namespace dali {
    enum class RendererAPI {
        None = 0,
        OpenGL
    };

    class Renderer {
    public:
        static RendererAPI get_api() {
            return s_renderer_api;
        }

    private:
        static RendererAPI s_renderer_api;
    };
}

#endif //__DALI_RENDERER_RENDERER_H
