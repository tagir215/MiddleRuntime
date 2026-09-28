#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEINSERTABLEBUBBLE(X)

namespace components {

	struct InsertableBubble  {

	};

    template<typename V>
    static void reflectInsertableBubble(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<InsertableBubble>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEINSERTABLEBUBBLE(X)
        #undef X
    }
}
