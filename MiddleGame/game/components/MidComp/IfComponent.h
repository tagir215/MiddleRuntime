#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEIFCOMPONENT(X) \
	X(type)

namespace components {
	struct IfComponent {
		int type = 0;

	};

    template<typename V>
    static void reflectIfComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<IfComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEIFCOMPONENT(X)
        #undef X
    }
}
