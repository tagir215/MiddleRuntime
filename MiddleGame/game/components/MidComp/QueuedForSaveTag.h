#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEQUEUEDFORSAVETAG(X) 

namespace components {
	struct QueuedForSaveTag {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<QueuedForSaveTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEQUEUEDFORSAVETAG(X)
        #undef X
    }
}
