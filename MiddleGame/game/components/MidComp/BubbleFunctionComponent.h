#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEFUNCTIONCOMPONENT(X) \
	X(label)

namespace components {
	struct BubbleFunctionComponent {
		std::string label;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubbleFunctionComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEFUNCTIONCOMPONENT(X)
        #undef X
    }
}
