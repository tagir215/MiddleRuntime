#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLESUMCOMPONENT(X) 

namespace components {
	struct BubbleSumComponent {

	};

    template<typename V>
    static void reflectBubbleSumComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleSumComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLESUMCOMPONENT(X)
        #undef X
    }
}
