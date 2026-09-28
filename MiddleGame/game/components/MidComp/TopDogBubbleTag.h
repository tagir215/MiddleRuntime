#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETOPDOGBUBBLETAG(X)

namespace components {
	struct TopDogBubbleTag {

	};

    template<typename V>
    static void reflectTopDogBubbleTag(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<TopDogBubbleTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLETOPDOGBUBBLETAG(X)
        #undef X
    }
}
