//
// Created by Leo on 5/3/2020.
//

#ifndef __DALI_IMGUI_LAYER_H
#define __DALI_IMGUI_LAYER_H

#include <dali/layer.h>
#include <dali/event.h>

namespace dali {
    class ImGuiLayer : public Layer {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        virtual void on_attach() override;
        virtual void on_detach() override;
        virtual void on_imgui_render() override;

        void begin();
        void end();

    private:
        float m_time = 0.0f;
    };
}

#endif //DALI_IMGUI_LAYER_H
