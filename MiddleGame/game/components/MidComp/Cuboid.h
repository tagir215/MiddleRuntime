#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECUBOID(X) \
	X(width) \
	X(height) \
	X(length)

namespace components {
	struct Cuboid {
		float width = 0;
		float height = 0;
		float length = 0;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Cuboid>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLECUBOID(X)
        #undef X
    }
}
