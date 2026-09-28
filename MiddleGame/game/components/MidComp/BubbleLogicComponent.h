#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLELOGICCOMPONENT(X) 

namespace components {
	enum BubbleLogicRole {
		LEFT,
		RIGHT
	};
	struct BubbleLogicComponent {

	};

    template<typename V>
    static void reflectBubbleLogicComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleLogicComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLELOGICCOMPONENT(X)
        #undef X
    }
}
