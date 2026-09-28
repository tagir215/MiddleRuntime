#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECONFIGCOMPONENT(X)

namespace components {
	struct ConfigComponent {

	};

    template<typename V>
    static void reflectConfigComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<ConfigComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLECONFIGCOMPONENT(X)
        #undef X
    }
}
