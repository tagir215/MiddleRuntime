#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESNAPREF(X) 

namespace components {
	struct SnapRef {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<SnapRef>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLESNAPREF(X)
        #undef X
    }
}
