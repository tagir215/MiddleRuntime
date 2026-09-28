#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#include "bubble_actions.h"
#define MIDDLEINPUTVARIABLE(X) \
	X(unitRef) \
	X(rootNodeId) \
	X(startPointNodeId)

namespace components {
	struct InputVariable {
		middle::Id unitRef;
		middle::Id rootNodeId;
		middle::Id startPointNodeId;

	};

    template<typename V>
    static void reflectInputVariable(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<InputVariable>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEINPUTVARIABLE(X)
        #undef X
    }
}
