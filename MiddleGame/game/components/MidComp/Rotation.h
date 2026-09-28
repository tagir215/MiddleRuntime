#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEROTATION(X) \
	X(rotation)

namespace components {
	struct Rotation {
		midMath::Quaternion rotation;

	};

}

namespace middle {
	const midMath::Vector3 ROTATION_FORWARD = { 0,1,0 };

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Rotation>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEROTATION(X)
        #undef X
    }
}
