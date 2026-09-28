#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEMOUSESELECTABLE(X)

namespace components {
	struct MouseSelectable {
		bool selected = false;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<MouseSelectable>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEMOUSESELECTABLE(X)
        #undef X
    }
}
