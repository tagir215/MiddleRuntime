#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEGATECOMPONENT(X) \
	X(status)

namespace components {

	enum BubbleGateStatus {
		CLOSED,
		OPEN,
		DUMMY
	};

	struct BubbleGateComponent {
		int status = BubbleGateStatus::CLOSED;

	};

    template<typename V>
    static void reflectBubbleGateComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleGateComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEGATECOMPONENT(X)
        #undef X
    }
}
