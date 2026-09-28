#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLENEEDSUPDATETAG(X) 

namespace components {
	struct NeedsUpdateTag {

	};

    template<typename V>
    static void reflectNeedsUpdateTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<NeedsUpdateTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLENEEDSUPDATETAG(X)
        #undef X
    }
}
