//
// Created by Leo on 5/16/2020.
//

#ifndef __DALI_RENDERER_CONTEXT_H
#define __DALI_RENDERER_CONTEXT_H

namespace dali {
    class GraphicsContext {
    public:
        virtual void init() = 0;

        virtual void swap_buffers() = 0;
    };
}

#endif //__DALI_CONTEXT_H
