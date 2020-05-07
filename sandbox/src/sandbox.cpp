//
// Created by Leo on 4/23/2020.
//
#include <dali/dali.h>
#include <dali/entrypoint.h>

class ExampleLayer : public dali::Layer {
public:
    ExampleLayer()
            : Layer("Example") {
    }

    void on_update() override {
//        DALI_INFO("ExampleLayer: update");
    }

    void on_event(dali::Event &event) override {
        DALI_TRACE("{}", event);
    }
};

class Sandbox : public dali::App {
public:
    Sandbox() {
        push_layer(new ExampleLayer());
        push_overlay(new dali::ImGuiLayer());
    }

    ~Sandbox() {

    }
};

dali::App *dali::create_app() {
    return new Sandbox();
}
