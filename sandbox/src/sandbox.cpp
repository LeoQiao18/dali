//
// Created by Leo on 4/23/2020.
//
#include <dali.h>
#include <dali/entrypoint.h>

class Sandbox : public dali::Application {
public:
    Sandbox() {

    }

    ~Sandbox() {

    }
};

dali::Application *dali::create_application() {
    return new Sandbox();
}
