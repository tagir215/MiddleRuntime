#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESELECTEDCOMPONENT(X) 

namespace components {
	struct SelectedComponent {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<SelectedComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLESELECTEDCOMPONENT(X)
        #undef X
    }
}
