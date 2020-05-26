//
// Created by Leo on 5/24/2020.
//

#include <dali/renderer/buffer.h>
#include <dali/renderer/renderer.h>
#include <dali/core.h>

#include <dali/platform/opengl/buffer.h>

namespace dali {
    VertexBuffer *VertexBuffer::create(float *vertices, uint32_t size) {
        switch (Renderer::get_api()) {
            case RendererAPI::None:
                DALI_CORE_ASSERT(false, "RendererAPI::None is not supported!");
                return nullptr;
            case RendererAPI::OpenGL:
                return new OpenGLVertexBuffer(vertices, size);
        }

        DALI_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    IndexBuffer *IndexBuffer::create(uint32_t *indices, uint32_t count) {
        switch (Renderer::get_api()) {
            case RendererAPI::None:
                DALI_CORE_ASSERT(false, "RendererAPI::None is not supported!");
                return nullptr;
            case RendererAPI::OpenGL:
                return new OpenGLIndexBuffer(indices, count);
        }

        DALI_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
