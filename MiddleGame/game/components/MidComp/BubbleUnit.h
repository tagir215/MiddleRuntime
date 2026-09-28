#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEUNIT(X) \
	X(value)

namespace components {
	struct BubbleUnit {
		int value = 1;

	};

    template<typename V>
    static void reflectBubbleUnit(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubbleUnit>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEUNIT(X)
        #undef X
    }
}
