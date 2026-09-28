#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECIRCLE(X) \
	X(radius)

namespace components {
	struct Circle {
		float radius;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Circle>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLECIRCLE(X)
        #undef X
    }
}
