//
// Created by Leo on 5/23/2020.
//

#ifndef __DALI_RENDERER_SHADER_H
#define __DALI_RENDERER_SHADER_H

#include <dali/common.h>

namespace dali {
    class Shader {
    public:
        Shader(std::string vertex_src, std::string fragment_src);

        ~Shader();

        void bind() const;

        void unbind() const;

    protected:
        uint32_t m_program_id;
    };
}

#endif //__DALI_RENDERER_SHADER_H
