//
// Created by Leo on 5/1/2020.
//

#ifndef DALI_LAYER_H
#define DALI_LAYER_H

#include <dali/core.h>
#include <dali/event.h>

namespace dali {
    /*
     * Layer.
     */
    class DALI_API Layer {
    public:
        Layer(const std::string &name = "Layer");

        virtual ~Layer();

        virtual void on_attach() {};

        virtual void on_detach() {};

        virtual void on_update() {};

        virtual void on_event(Event &event) {};

        inline const std::string &get_name() const {
            return m_name;
        }

    private:
        std::string m_name;
    };

    /*
     * LayerStack.
     *
     * Note: LayerStack has ownership over the Layers.
     */
    class DALI_API LayerStack {
    public:
        LayerStack() = default;

        ~LayerStack();

        void push_layer(Layer *layer);

        void push_overlay(Layer *layer);

        void pop_layer(Layer *layer);

        void pop_overlay(Layer *layer);

        std::vector<Layer *>::iterator begin() {
            return m_layers.begin();
        }

        std::vector<Layer *>::iterator end() {
            return m_layers.end();
        }

        std::vector<Layer *>::reverse_iterator rbegin() {
            return m_layers.rbegin();
        }

        std::vector<Layer *>::reverse_iterator rend() {
            return m_layers.rend();
        }

        std::vector<Layer *>::const_iterator begin() const {
            return m_layers.begin();
        }

        std::vector<Layer *>::const_iterator end() const {
            return m_layers.end();
        }

        std::vector<Layer *>::const_reverse_iterator rbegin() const {
            return m_layers.rbegin();
        }

        std::vector<Layer *>::const_reverse_iterator rend() const {
            return m_layers.rend();
        }

    private:
        std::vector<Layer *> m_layers;
        unsigned int m_layer_insert_index = 0;
    };
}

#endif //DALI_LAYER_H
