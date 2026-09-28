#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEGLOBALRADIUS(X) \
	X(radius)

namespace components {
	struct GlobalRadius {
		float radius;

	};

    template<typename V>
    static void reflectGlobalRadius(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<GlobalRadius>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEGLOBALRADIUS(X)
        #undef X
    }
}
