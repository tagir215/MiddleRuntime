#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESCOPECOMPONENT(X)

namespace components {
	struct ScopeComponent {

	};

    template<typename V>
    static void reflectScopeComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<ScopeComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLESCOPECOMPONENT(X)
        #undef X
    }
}
