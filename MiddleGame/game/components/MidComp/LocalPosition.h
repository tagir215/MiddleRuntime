#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLELOCALPOSITION(X) \
	X(pos)

namespace components {
	struct LocalPosition {
		midMath::Vector3 pos = { 0,0,0 };

	};

    template<typename V>
    static void reflectLocalPosition(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<LocalPosition>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLELOCALPOSITION(X)
        #undef X
    }
}
