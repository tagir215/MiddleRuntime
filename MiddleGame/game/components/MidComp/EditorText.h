#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEEDITORTEXT(X) \
	X(text)

namespace components {
	struct EditorText {
		std::string text;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<EditorText>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEEDITORTEXT(X)
        #undef X
    }
}
