#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEEQUALSVARIABLE(X) 

namespace components {
	struct BubbleEqualsVariable {
		std::string variableLabel;
		bool wantsToReplaceVariable = false;
		bool wantsToReplaceBubble = false;
		middle::Id matchingIdRef;

	};

    template<typename V>
    static void reflectBubbleEqualsVariable(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleEqualsVariable>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEEQUALSVARIABLE(X)
        #undef X
    }
}
