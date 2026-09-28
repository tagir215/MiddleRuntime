#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
# define MIDDLEMOUSEGRABBABLE(X) 

namespace components {
	struct MouseGrabbable {
		bool grabbing = false;

	};

    template<typename V>
    static void reflectMouseGrabbable(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<MouseGrabbable>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEMOUSEGRABBABLE(X)
        #undef X
    }
}
