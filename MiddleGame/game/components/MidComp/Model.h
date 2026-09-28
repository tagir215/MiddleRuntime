#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEMODELCOMPONENT(X) \
	X(path)

namespace components {
	struct ModelComponent {
		std::string path;
		Model model;

	};

    template<typename V>
    static void reflectModel(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Model>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEMODEL(X)
        #undef X
    }
}
