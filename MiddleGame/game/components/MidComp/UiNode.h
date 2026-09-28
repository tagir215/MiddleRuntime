#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEUINODE(X) 

namespace components {
	struct UiNode {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<UiNode>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEUINODE(X)
        #undef X
    }
}
