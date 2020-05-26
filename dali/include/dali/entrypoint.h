//
// Created by Leo on 4/24/2020.
//

#ifndef __DALI_ENTRYPOINT_H
#define __DALI_ENTRYPOINT_H

#include <dali/app.h>
#include <dali/common.h>

int main(int argc, char **argv) {
    // Dali initializations
    dali::Log::init();

    // Instantiate client app
    auto app = dali::create_app();
    DALI_CORE_INFO("App created\n");
    app->run();
    delete app;
}

#endif //__DALI_ENTRYPOINT_H
