#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLESWAPCOMPONENT(X) \
	X(activeIndex)

namespace components {

	enum BubbleSwapRole {
		WORD_PROBLEM,
		SOLUTION_BUBBLE
	};

	enum SwapComponentStatus {
		SWAP_DISABLED,
		SWAP_ENABLED
	};

	struct BubbleSwapComponent {
		int activeIndex = 0;
		SwapComponentStatus status;

	};

    template<typename V>
    static void reflectBubbleSwapComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleSwapComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLESWAPCOMPONENT(X)
        #undef X
    }
}
