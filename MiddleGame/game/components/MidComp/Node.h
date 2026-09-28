#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLENODE(X)

namespace components {
	struct Node {

	};

    template<typename V>
    static void reflectNode(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<Node>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLENODE(X)
        #undef X
    }
}
