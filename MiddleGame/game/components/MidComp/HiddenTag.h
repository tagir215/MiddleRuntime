#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEHIDDENTAG(X)

namespace components {
	struct HiddenTag {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<HiddenTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEHIDDENTAG(X)
        #undef X
    }
}
