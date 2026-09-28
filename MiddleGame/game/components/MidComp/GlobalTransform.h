#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEGLOBALTRANSFORM(X) \
	X(pos) \
	X(scale) \
	X(rotation) 

namespace components {
	struct GlobalTransform {
		midMath::Vector3 pos = { 0,0,0 };
		midMath::Vector3 scale = { 1,1,1 };
		midMath::Quaternion rotation = {0,0,0,0};

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<GlobalTransform>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEGLOBALTRANSFORM(X)
        #undef X
    }
}
