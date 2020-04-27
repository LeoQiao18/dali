//
// Created by Leo on 4/23/2020.
//
#include <dali/dali.h>
#include <dali/entrypoint.h>

class Sandbox : public dali::App {
public:
    Sandbox() {

    }

    ~Sandbox() {

    }
};

dali::App *dali::create_app() {
    return new Sandbox();
}
