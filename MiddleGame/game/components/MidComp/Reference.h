#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEREFERENCE(X) \
	X(sceneName) \
	X(folder)

namespace components {
	struct Reference {
		std::string sceneName;
		std::string folder;

	};

    template<typename V>
    static void reflectReference(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Reference>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEREFERENCE(X)
        #undef X
    }
}
