#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEMULTIPLYCOMPONENT(X) \
	X(operationType)

namespace components {
	struct BubbleMultiplyComponent {
		int operationType = 0;

	};


    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubbleMultiplyComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEMULTIPLYCOMPONENT(X)
        #undef X
    }
}
