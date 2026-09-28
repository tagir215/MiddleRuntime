#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEOFFSET(X) \
	X(offsetX) \
	X(offsetY) \
	X(offsetZ) 

namespace components {
	struct Offset {
		float offsetX = 0;
		float offsetY = 0;
		float offsetZ = 0;

	};

    template<typename V>
    static void reflectOffset(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Offset>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEOFFSET(X)
        #undef X
    }
}
