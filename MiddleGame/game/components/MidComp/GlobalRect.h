#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEGLOBALRECT(X) \
	X(width) \
	X(height)


namespace components {
	struct GlobalRect {
		float width;
		float height;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<GlobalRect>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEGLOBALRECT(X)
        #undef X
    }
}
