//
// Created by Leo on 5/24/2020.
//

#ifndef __DALI_RENDERER_BUFFER_H
#define __DALI_RENDERER_BUFFER_H

#include <dali/common.h>

#include <utility>

namespace dali {
    /*
     * ShaderDataType.
     */
    enum class ShaderDataType {
        None = 0,
        Float, Float2, Float3, Float4,
        Int, Int2, Int3, Int4,
        Mat3, Mat4,
        Bool
    };

    static uint32_t get_shader_data_type_size(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::Float:
                return 4;
            case ShaderDataType::Float2:
                return 4 * 2;
            case ShaderDataType::Float3:
                return 4 * 3;
            case ShaderDataType::Float4:
                return 4 * 4;
            case ShaderDataType::Int:
                return 4;
            case ShaderDataType::Int2:
                return 4 * 2;
            case ShaderDataType::Int3:
                return 4 * 3;
            case ShaderDataType::Int4:
                return 4 * 4;
            case ShaderDataType::Mat3:
                return 4 * 3 * 3;
            case ShaderDataType::Mat4:
                return 4 * 4 * 4;
            case ShaderDataType::Bool:
                return 1;
        }

        DALI_CORE_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }

    /*
     * BufferElement.
     */
    struct BufferElement {
        std::string name;
        ShaderDataType type;
        uint32_t size;
        uint32_t offset;
        bool normalized;

        BufferElement() = default;

        BufferElement(ShaderDataType type_, const std::string &name_, bool normalized_ = false)
                : type(type_), name(name_), size(get_shader_data_type_size(type_)), offset(0), normalized(normalized_) {
        }

        uint32_t get_count() const {
            switch (type) {
                case ShaderDataType::Float:
                    return 1;
                case ShaderDataType::Float2:
                    return 2;
                case ShaderDataType::Float3:
                    return 3;
                case ShaderDataType::Float4:
                    return 4;
                case ShaderDataType::Int:
                    return 1;
                case ShaderDataType::Int2:
                    return 2;
                case ShaderDataType::Int3:
                    return 3;
                case ShaderDataType::Int4:
                    return 4;
                case ShaderDataType::Mat3:
                    return 3 * 3;
                case ShaderDataType::Mat4:
                    return 4 * 4;
                case ShaderDataType::Bool:
                    return 1;
            }

            DALI_CORE_ASSERT(false, "Unknown ShaderDataType!");
            return 0;
        }
    };

    /*
     * BufferLayout.
     *
     * Contains the layout of VertexBuffer, as a vector of BufferElements.
     */
    class BufferLayout {
    public:
        BufferLayout() = default;

        BufferLayout(std::initializer_list<BufferElement> elements)
                : m_elements(elements) {
            calculate_offsets_and_strides();
        }

        const std::vector<BufferElement> &get_elements() const {
            return m_elements;
        }

        uint32_t get_stride() const {
            return m_stride;
        }

        std::vector<BufferElement>::iterator begin() {
            return m_elements.begin();
        }

        std::vector<BufferElement>::iterator end() {
            return m_elements.end();
        }

        std::vector<BufferElement>::reverse_iterator rbegin() {
            return m_elements.rbegin();
        }

        std::vector<BufferElement>::reverse_iterator rend() {
            return m_elements.rend();
        }

        std::vector<BufferElement>::const_iterator begin() const {
            return m_elements.begin();
        }

        std::vector<BufferElement>::const_iterator end() const {
            return m_elements.end();
        }

        std::vector<BufferElement>::const_reverse_iterator rbegin() const {
            return m_elements.rbegin();
        }

        std::vector<BufferElement>::const_reverse_iterator rend() const {
            return m_elements.rend();
        }

    private:
        void calculate_offsets_and_strides() {
            uint32_t offset = 0;
            for (BufferElement &e : m_elements) {
                e.offset = offset;
                offset += e.size;
            }
            m_stride = offset;
        }

        std::vector<BufferElement> m_elements;
        uint32_t m_stride = 0;
    };

    /*
     * VertexBuffer.
     */
    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;;

        virtual void bind() const = 0;

        virtual void unbind() const = 0;

        virtual void set_layout(const BufferLayout &layout) = 0;

        virtual const BufferLayout &get_layout() const = 0;

        static VertexBuffer *create(float *vertices, uint32_t size);
    };

    /*
     * IndexBuffer.
     */
    class IndexBuffer {
    public:
        virtual ~IndexBuffer() = default;;

        virtual void bind() const = 0;

        virtual void unbind() const = 0;

        virtual uint32_t get_count() const = 0;

        static IndexBuffer *create(uint32_t *indices, uint32_t count);
    };
}

#endif //__DALI_RENDERER_BUFFER_H
