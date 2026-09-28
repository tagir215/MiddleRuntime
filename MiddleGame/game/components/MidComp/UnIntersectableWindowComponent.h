#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEUNINTERSECTABLEWINDOWCOMPONENT(X) 

namespace components {
	struct UnIntersectableWindowComponent {
		float timeLeft = 0;

	};

    template<typename V>
    static void reflectUnIntersectableWindowComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<UnIntersectableWindowComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEUNINTERSECTABLEWINDOWCOMPONENT(X)
        #undef X
    }
}
