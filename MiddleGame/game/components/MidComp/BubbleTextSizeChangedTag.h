#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLETEXTSIZECHANGEDTAG(X)

namespace components {
	struct BubbleTextSizeChangedTag {

	};

    template<typename V>
    static void reflectBubbleTextSizeChangedTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubbleTextSizeChangedTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLETEXTSIZECHANGEDTAG(X)
        #undef X
    }
}
