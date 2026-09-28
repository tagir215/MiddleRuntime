#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETIMERCOMPONENT(X) \
	X(timeLeft)

namespace components {
	struct TimerComponent {
		float timeLeft = 0;

	};

    template<typename V>
    static void reflectTimerComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<TimerComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLETIMERCOMPONENT(X)
        #undef X
    }
}
