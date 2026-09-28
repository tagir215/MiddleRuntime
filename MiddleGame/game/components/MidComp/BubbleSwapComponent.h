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

	struct BubbleSwapComponent : public middle::Serializable{
		int activeIndex = 0;
		SwapComponentStatus status;

	};
}
