#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEVARIABLE(X) \
	X(label) \
	X(isNegative)


namespace components {
	struct BubbleVariable {
		std::string label;
		bool isNegative = false;

	};

    template<typename V>
    static void reflectBubbleVariable(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleVariable>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEVARIABLE(X)
        #undef X
    }
}
