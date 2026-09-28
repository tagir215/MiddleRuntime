#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEMODIFIEDBUBBLETAG(X) 

namespace components {
	struct ModifiedBubbleTag {

	};

    template<typename V>
    static void reflectModifiedBubbleTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<ModifiedBubbleTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEMODIFIEDBUBBLETAG(X)
        #undef X
    }
}
