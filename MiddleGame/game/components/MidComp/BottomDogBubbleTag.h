#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBOTTOMDOGBUBBLETAG(X) 

namespace components {
	struct BottomDogBubbleTag {

	};

    template<typename V>
    static void reflectBottomDogBubbleTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BottomDogBubbleTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBOTTOMDOGBUBBLETAG(X)
        #undef X
    }
}
