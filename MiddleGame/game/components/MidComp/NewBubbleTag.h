#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLENEWBUBBLETAG(X)

namespace components {
	struct NewBubbleTag {

	};

    template<typename V>
    static void reflectNewBubbleTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<NewBubbleTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLENEWBUBBLETAG(X)
        #undef X
    }
}
