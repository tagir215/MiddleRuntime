#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEPROCEDURECOMPONENT(X) 

namespace components {
	struct BubbleProcedureComponent {

	};

    template<typename V>
    static void reflectBubbleProcedureComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleProcedureComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEPROCEDURECOMPONENT(X)
        #undef X
    }
}
