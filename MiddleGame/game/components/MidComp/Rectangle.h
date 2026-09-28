#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLERECTANGLE(X) \
	X(width) \
	X(height)

namespace components {
	struct Rectangle {
		float width = 0;
		float height = 0;

	};

    template<typename V>
    static void reflectRectangle(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Rectangle>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLERECTANGLE(X)
        #undef X
    }
}
