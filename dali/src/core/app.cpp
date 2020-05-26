//
// Created by Leo on 4/23/2020.
//

#include <dali/app.h>
#include <dali/common.h>
#include <dali/event.h>
#include <dali/input.h>

#include <dali/renderer/shader.h>

#include <glad/glad.h>


namespace dali {

    App *App::s_instance = nullptr;

    static GLenum shader_type_to_opengl_type(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::Float:
                return GL_FLOAT;
            case ShaderDataType::Float2:
                return GL_FLOAT;
            case ShaderDataType::Float3:
                return GL_FLOAT;
            case ShaderDataType::Float4:
                return GL_FLOAT;
            case ShaderDataType::Int:
                return GL_INT;
            case ShaderDataType::Int2:
                return GL_INT;
            case ShaderDataType::Int3:
                return GL_INT;
            case ShaderDataType::Int4:
                return GL_INT;
            case ShaderDataType::Mat3:
                return GL_FLOAT;
            case ShaderDataType::Mat4:
                return GL_FLOAT;
            case ShaderDataType::Bool:
                return GL_BOOL;
        }

        DALI_CORE_ASSERT(false, "Unknown ShaderDataType!");
        return 0;
    }

    App::App() {
        DALI_CORE_ASSERT(!s_instance, "App already exists!");
        s_instance = this;

        m_window = std::unique_ptr<Window>(Window::create());
        m_window->set_event_callback(std::bind(&App::on_event, this, std::placeholders::_1));

        m_imgui_layer = new ImGuiLayer();
        push_overlay(m_imgui_layer);

        // TODO: quick triangle
        glGenVertexArrays(1, &m_vertex_array);
        glBindVertexArray(m_vertex_array);

        float vertices[4 * 3] = {
                -0.5f, -0.5f, 0.0f, 1.0f,
                0.5f, -0.5f, 0.0f, 1.0f,
                0.0f, 0.5f, 0.0f, 1.0f
        };

        BufferLayout layout = {
                {ShaderDataType::Float3, "a_position"},
                { ShaderDataType::Float, "random" }
        };

        m_vbo = std::unique_ptr<VertexBuffer>(VertexBuffer::create(vertices, sizeof(vertices)));
        m_vbo->set_layout(layout);

        uint32_t index = 0;
        for (const BufferElement &e : m_vbo->get_layout()) {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index,
                                  e.get_count(),
                                  shader_type_to_opengl_type(e.type),
                                  e.normalized ? GL_TRUE : GL_FALSE, m_vbo->get_layout().get_stride(),
                                  reinterpret_cast<const void *>(e.offset));
            index++;
        }

        uint32_t indices[3] = {0, 1, 2};
        m_ibo = std::unique_ptr<IndexBuffer>(IndexBuffer::create(indices, sizeof(indices) / sizeof(uint32_t)));

        //TODO: temp shader
        std::string vertex_src = R"(
#version 330 core

layout(location = 0) in vec3 a_position;

out vec3 v_position;

void main() {
    gl_Position = vec4(a_position, 1.0);
    v_position = a_position;
}
)";
        std::string fragment_src = R"(
#version 330 core

in vec3 v_position;

layout(location = 0) out vec4 color;

void main() {
    color = vec4(v_position, 1.0);
}
)";
        m_shader = std::make_unique<Shader>(vertex_src, fragment_src);
    }

    App::~App() {

    }

    void App::run() {
        while (m_running) {
            glClearColor(0.1f, 0.1f, 0.1f, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            m_shader->bind();
            glBindVertexArray(m_vertex_array);
            glDrawElements(GL_TRIANGLES, m_ibo->get_count(), GL_UNSIGNED_INT, nullptr);

            for (Layer *layer : m_layer_stack) {
                layer->on_update();
            }

            m_imgui_layer->begin();
            for (Layer *layer : m_layer_stack) {
                layer->on_imgui_render();
            }
            m_imgui_layer->end();

            m_window->on_update();
        }
    }

    void App::on_event(Event &e) {
        EventDispatcher dispatcher(e);
        dispatcher.dispatch<WindowCloseEvent>(std::bind(&App::on_window_close, this, std::placeholders::_1));

        for (auto it = m_layer_stack.rbegin(); it != m_layer_stack.rend(); ++it) {
            (*it)->on_event(e);

            if (e.m_handled) {
                break;
            }
        }
    }

    bool App::on_window_close(WindowCloseEvent &e) {
        m_running = false;
        return true;
    }

    void App::push_layer(Layer *layer) {
        m_layer_stack.push_layer(layer);
    }

    void App::push_overlay(Layer *layer) {
        m_layer_stack.push_overlay(layer);
    }

}
