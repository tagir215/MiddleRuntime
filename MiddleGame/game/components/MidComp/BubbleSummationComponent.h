#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLESUMMATIONCOMPONENT(X) 

namespace components {
	enum SummationRole {
		INDEX,
		UPPER_LIMIT,
		SUMMAND
	};

	enum SummationIndexRole {
		INDEX_VARIABLE,
		INDEX_VALUE
	};

	struct BubbleSummationComponent {

	};

    template<typename V>
    static void reflectBubbleSummationComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleSummationComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLESUMMATIONCOMPONENT(X)
        #undef X
    }
}
