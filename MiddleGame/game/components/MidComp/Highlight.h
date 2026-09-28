#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEHIGHLIGHT(X) 

namespace components {
	struct Highlight {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Highlight>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEHIGHLIGHT(X)
        #undef X
    }
}
