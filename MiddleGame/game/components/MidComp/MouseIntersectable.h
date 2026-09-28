#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEMOUSEINTERSECTABLE(X) \


namespace components {
	struct MouseIntersectable {

	};

    template<typename V>
    static void reflectMouseIntersectable(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<MouseIntersectable>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEMOUSEINTERSECTABLE(X)
        #undef X
    }
}
