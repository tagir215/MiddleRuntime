#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEDELETECOMPONENT(X) 

namespace components {
	struct DeleteComponent {
		int framesUntilDelete = 0;
	};

    template<typename V>
    static void reflectDeleteComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<DeleteComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEDELETECOMPONENT(X)
        #undef X
    }
}
