#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLELOCKEDCOMPONENT(X) 

namespace components {
	struct BubbleLockedComponent {

	};

    template<typename V>
    static void reflectBubbleLockedComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubbleLockedComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLELOCKEDCOMPONENT(X)
        #undef X
    }
}
