#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPOSITION(X) \
	X(posX) \
	X(posY) \
	X(posZ) 

namespace components {
	struct Position {
		float posX;
		float posY;
		float posZ;

	};

    template<typename V>
    static void reflectPosition(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<Position>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPOSITION(X)
        #undef X
    }
}
