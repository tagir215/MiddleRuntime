#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEINACTIVETAG(X) 

namespace components {
	struct InactiveTag {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<InactiveTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEINACTIVETAG(X)
        #undef X
    }
}
