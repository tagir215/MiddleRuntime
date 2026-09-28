#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESYSTEMREFERENCE(X) \
	X(systemName)

namespace components {
	struct SystemReference {
		std::string systemName;

	};

    template<typename V>
    static void reflectSystemReference(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<SystemReference>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLESYSTEMREFERENCE(X)
        #undef X
    }
}
