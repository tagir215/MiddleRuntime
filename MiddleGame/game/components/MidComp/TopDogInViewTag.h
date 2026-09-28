#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETOPDOGINVIEWTAG(X) 

namespace components {
	struct TopDogInViewTag {

	};

    template<typename V>
    static void reflectTopDogInViewTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<TopDogInViewTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLETOPDOGINVIEWTAG(X)
        #undef X
    }
}
