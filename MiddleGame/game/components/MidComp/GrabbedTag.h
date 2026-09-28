#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEGRABBEDTAG(X)

namespace components {
	struct GrabbedTag {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<GrabbedTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEGRABBEDTAG(X)
        #undef X
    }
}
