#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEEQUALSCOMPONENT(X)

namespace components {

	enum BubbleEqualsRole {
		EQUALS_LEFT,
		EQUALS_RIGHT
	};

	struct BubbleEqualsComponent {

	};

    template<typename V>
    static void reflectBubbleEqualsComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<BubbleEqualsComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLEEQUALSCOMPONENT(X)
        #undef X
    }
}
