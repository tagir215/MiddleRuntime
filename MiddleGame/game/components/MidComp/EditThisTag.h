#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEEDITTHISTAG(X) 

namespace components {
	struct EditThisTag {

	};

    template<typename V>
    static void reflectEditThisTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<EditThisTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEEDITTHISTAG(X)
        #undef X
    }
}
