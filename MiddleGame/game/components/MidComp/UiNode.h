#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEUINODE(X) 

namespace components {
	struct UiNode {

	};

    template<typename V>
    static void reflectUiNode(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<UiNode>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEUINODE(X)
        #undef X
    }
}
