#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPLACEMENTCOMPONENT(X) 

namespace components {
	struct PlacementComponent {
		bool grabbing = true;

	};

    template<typename V>
    static void reflectPlacementComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<PlacementComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPLACEMENTCOMPONENT(X)
        #undef X
    }
}
