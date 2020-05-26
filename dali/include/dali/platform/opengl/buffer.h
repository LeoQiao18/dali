//
// Created by Leo on 5/24/2020.
//

#ifndef __DALI_PLATFORM_OPENGL_BUFFER_H
#define __DALI_PLATFORM_OPENGL_BUFFER_H

#include <dali/common.h>
#include <dali/renderer/buffer.h>

namespace dali {
    class OpenGLVertexBuffer : public VertexBuffer {
    public:
        OpenGLVertexBuffer(float *vertices, uint32_t size);

        virtual ~OpenGLVertexBuffer();

        virtual void bind() const override;

        virtual void unbind() const override;

        virtual void set_layout(const BufferLayout &layout) {
            m_layout = layout;
        }

        virtual const BufferLayout &get_layout() const {
            return m_layout;
        }

    private:
        uint32_t m_buffer_id;
        BufferLayout m_layout;
    };

    class OpenGLIndexBuffer : public IndexBuffer {
    public:
        OpenGLIndexBuffer(uint32_t *indices, uint32_t count);

        virtual ~OpenGLIndexBuffer();

        virtual void bind() const override;

        virtual void unbind() const override;

        virtual uint32_t get_count() const override {
            return m_count;
        };

    private:
        uint32_t m_buffer_id;
        uint32_t m_count;
    };
}

#endif //__DALI_PLATFORM_OPENGL_BUFFER_H
