#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEREF(X)

namespace components {
	struct BubbleRef {
		middle::Id idRef;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubbleRef>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEREF(X)
        #undef X
    }
}
