//
// Created by Leo on 4/23/2020.
//
#include <Dali.h>

class Sandbox : public Dali::Application {
public:
    Sandbox() {

    }

    ~Sandbox() {

    }
};

Dali::Application *Dali::CreateApplication() {
    return new Sandbox();
}
