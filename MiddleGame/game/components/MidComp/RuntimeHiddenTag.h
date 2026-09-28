#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLERUNTIMEHIDDENTAG(X)

namespace components {
	struct RuntimeHiddenTag {

	};

    template<typename V>
    static void reflectRuntimeHiddenTag(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<RuntimeHiddenTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLERUNTIMEHIDDENTAG(X)
        #undef X
    }
}
