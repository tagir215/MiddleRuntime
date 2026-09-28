#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEACTIVESCENEEDITABLETAG(X) 

namespace components {
	struct ActiveSceneSelectableTag {
	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<ActiveSceneEditableTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEACTIVESCENEEDITABLETAG(X)
        #undef X
    }
}
