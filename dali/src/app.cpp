//
// Created by Leo on 4/23/2020.
//

#include <dali/app.h>
#include <dali/event.h>
#include <dali/log.h>
#include <iostream>

namespace dali {

    App::App() {

    }

    App::~App() {

    }

    void App::run() {
        WindowResizeEvent e(100, 200);
        if (e.get_type() == WindowResizeEvent::get_static_type()) {
            DALI_CORE_TRACE(e);
        }
        if (e.is_in_category(EventCategoryApplication)) {
            DALI_TRACE(e);
        }
        while (true);
    }

}
