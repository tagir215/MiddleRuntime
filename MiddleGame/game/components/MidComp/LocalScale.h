#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLELOCALSCALE(X) \
	X(scale)

namespace components {
	struct LocalScale {
		midMath::Vector3 scale = { 1,1,1 };

	};

    template<typename V>
    static void reflectLocalScale(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<LocalScale>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLELOCALSCALE(X)
        #undef X
    }
}
