//
// Created by Leo on 4/24/2020.
//

#ifndef DALI_ENTRYPOINT_H
#define DALI_ENTRYPOINT_H

extern Dali::Application* Dali::CreateApplication();

int main(int argc, char **argv) {
    auto app = Dali::CreateApplication();
    app->Run();
    delete app;
}

#endif //DALI_ENTRYPOINT_H
