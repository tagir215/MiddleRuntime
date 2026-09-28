#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLELOOPTAG(X) 
	

namespace components {
	struct LoopTag {

	};

    template<typename V>
    static void reflectLoopTag(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<LoopTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLELOOPTAG(X)
        #undef X
    }
}
