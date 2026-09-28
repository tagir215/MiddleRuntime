#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEFRACTIONALCOMPONENT(X)

namespace components {
	struct FractionalComponent {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<FractionalComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEFRACTIONALCOMPONENT(X)
        #undef X
    }
}
