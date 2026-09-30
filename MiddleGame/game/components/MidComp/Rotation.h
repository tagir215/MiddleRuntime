#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEROTATION(X) \
	X(rotation)

namespace components {
	struct Rotation {
		midMath::Quaternion rotation;

	};

    template<typename V>
    static void reflectRotation(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<Rotation>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEROTATION(X)
        #undef X
    }
}

