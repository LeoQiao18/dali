//
// Created by Leo on 4/24/2020.
//

#ifndef DALI_ENTRYPOINT_H
#define DALI_ENTRYPOINT_H

extern dali::Application* dali::create_application();

int main(int argc, char **argv) {
    auto app = dali::create_application();
    app->run();
    delete app;
}

#endif //DALI_ENTRYPOINT_H
