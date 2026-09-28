#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEMOUSECLICKCOMPONENT(X) 

namespace components {
	struct MouseClickComponent {

	};

    template<typename V>
    static void reflectMouseClickComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<MouseClickComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEMOUSECLICKCOMPONENT(X)
        #undef X
    }
}
