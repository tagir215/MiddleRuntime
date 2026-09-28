#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEALGEBRALEVELCONFIGS(X) \
	X(allowedMoves) \
	X(levelName) 

namespace components {
	struct BubbleAlgebraLevelConfigs {
		int allowedMoves = 5;
		std::string levelName = "";
		bool initialized = false;

	};

    template<typename V>
    static void reflectBubbleAlgebraLevelConfigs(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleAlgebraLevelConfigs>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEALGEBRALEVELCONFIGS(X)
        #undef X
    }
}
