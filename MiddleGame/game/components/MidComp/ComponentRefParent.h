#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECOMPONENTREFPARENT(X) \
	X(memberIds)

namespace components {
	struct ComponentRefParent {
		std::vector<middle::Id>memberIds;
	};

    template<typename V>
    static void reflectComponentRefParent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<ComponentRefParent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLECOMPONENTREFPARENT(X)
        #undef X
    }
}
