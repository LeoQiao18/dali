//
// Created by Leo on 4/24/2020.
//

#ifndef DALI_ENTRYPOINT_H
#define DALI_ENTRYPOINT_H

#include <dali/application.h>

int main(int argc, char **argv) {
    dali::Log::init();

    auto app = dali::create_application();
    app->run();
    delete app;
}

#endif //DALI_ENTRYPOINT_H
