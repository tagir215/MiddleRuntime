#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEGRIDELEMENT(X)

namespace components {
	struct GridElement {

	};

    template<typename V>
    static void reflectGridElement(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<GridElement>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEGRIDELEMENT(X)
        #undef X
    }
}
