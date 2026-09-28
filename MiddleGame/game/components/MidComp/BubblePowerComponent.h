#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEPOWERCOMPONENT(X) 

namespace components {
	enum PowerRole {
		POWER_ROLE_BASE,
		POWER_ROLE_EXPONENT
	};
	struct BubblePowerComponent  {

	};

    template<typename V>
    static void reflectBubblePowerComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubblePowerComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEPOWERCOMPONENT(X)
        #undef X
    }
}
