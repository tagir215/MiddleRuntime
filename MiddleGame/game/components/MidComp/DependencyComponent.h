#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEDEPENDENCYCOMPONENT(X) \
	X(idRef)

namespace components {
	struct DependencyComponent {
		middle::Id idRef;

	};

    template<typename V>
    static void reflectDependencyComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<DependencyComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEDEPENDENCYCOMPONENT(X)
        #undef X
    }
}
