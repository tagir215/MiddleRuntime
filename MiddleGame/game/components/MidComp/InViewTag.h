#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEINVIEWTAG(X)

namespace components {
	struct InViewTag {

	};

    template<typename V>
    static void reflectInViewTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<InViewTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEINVIEWTAG(X)
        #undef X
    }
}
