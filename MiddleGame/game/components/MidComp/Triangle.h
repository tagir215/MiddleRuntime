#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETRIANGLE(X) \
	X(width) \
	X(height)

namespace components {
	struct Triangle {
		float width;
		float height;

	};

    template<typename V>
    static void reflectTriangle(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Triangle>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLETRIANGLE(X)
        #undef X
    }
}
