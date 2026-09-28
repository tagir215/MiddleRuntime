#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEMODELCOMPONENT(X) \
	X(path)

namespace components {
	struct ModelComponent {
		std::string path;
		midPrimitive::Model model;
		bool initialized = false;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<ModelComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEMODELCOMPONENT(X)
        #undef X
    }
}
