#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEMANIPULATABLE(X) 

namespace components {
	struct BubbleManipulatable {

	};

    template<typename V>
    static void reflectBubbleManipulatable(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubbleManipulatable>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEMANIPULATABLE(X)
        #undef X
    }
}
