#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECOMPONENTREFERENCE(X) \
	X(componentName)

namespace components {
	struct ComponentReference {
		std::string componentName;

	};

    template<typename V>
    static void reflectComponentReference(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<ComponentReference>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLECOMPONENTREFERENCE(X)
        #undef X
    }
}
