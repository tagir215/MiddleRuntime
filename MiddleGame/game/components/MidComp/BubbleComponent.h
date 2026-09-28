#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLECOMPONENT(X)


namespace components {
	struct BubbleComponent {
	};

    template<typename V>
    static void reflectBubbleComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLECOMPONENT(X)
        #undef X
    }
}
