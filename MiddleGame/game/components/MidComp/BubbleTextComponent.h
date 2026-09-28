#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLETEXTCOMPONENT(X) \
	X(textName) 

namespace components {
	struct BubbleTextComponent {
		std::string textName;
		std::string text;
		float fontSize;

	};

    template<typename V>
    static void reflectBubbleTextComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleTextComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLETEXTCOMPONENT(X)
        #undef X
    }
}
