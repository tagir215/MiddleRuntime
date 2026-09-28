#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLENONPHYSICALBUBBLETAG(X)

namespace components {
	struct NonPhysicalBubbleTag {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<NonPhysicalBubbleTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLENONPHYSICALBUBBLETAG(X)
        #undef X
    }
}
