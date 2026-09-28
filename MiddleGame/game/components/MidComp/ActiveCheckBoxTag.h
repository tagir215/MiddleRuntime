#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEACTIVECHECKBOXTAG(X) 

namespace components {
	struct ActiveCheckBoxTag {

	};

    template<typename V>
    static void reflectActiveCheckBoxTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<ActiveCheckBoxTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEACTIVECHECKBOXTAG(X)
        #undef X
    }
}
