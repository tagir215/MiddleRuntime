#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEINEQUALTYCOMPONENT(X) 

namespace components {
	enum InequaltyRole {
		INEQUAL_LESSER,
		INEQUAL_GREATER
	};

	struct BubbleInequaltyComponent  {
	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubbleInequaltyComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEINEQUALTYCOMPONENT(X)
        #undef X
    }
}
