#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEINITIALIZEDTAG(X) 

namespace components {
	struct InitializedTag {

	};

    template<typename V>
    static void reflectInitializedTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<InitializedTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEINITIALIZEDTAG(X)
        #undef X
    }
}
