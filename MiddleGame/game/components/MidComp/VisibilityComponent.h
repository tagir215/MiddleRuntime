#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEVISIBILITYCOMPONENT(X) \
	X(visible)

namespace components {
	struct VisibilityComponent {
		bool visible = true;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<VisibilityComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEVISIBILITYCOMPONENT(X)
        #undef X
    }
}
