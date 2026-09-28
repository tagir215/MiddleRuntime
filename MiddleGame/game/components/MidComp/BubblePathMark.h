#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEPATHMARK(X) 

namespace components {
	struct BubblePathMark {
		size_t stamp = 0;

	};

    template<typename V>
    static void reflectBubblePathMark(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubblePathMark>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEPATHMARK(X)
        #undef X
    }
}
