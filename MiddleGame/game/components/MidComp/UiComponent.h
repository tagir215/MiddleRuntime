#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEUICOMPONENT(X) \
	X(type)

namespace components {
	struct UiComponent {
		int type = middle::UNASSIGNED;

	};

    template<typename V>
    static void reflectUiComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<UiComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEUICOMPONENT(X)
        #undef X
    }
}

namespace UiElementTypes {
	static int MOVES_LEFT_INDICATOR = 0;
	static int UI_BACKGROUND = 1;
	static int OUT_OF_STEPS = 2;
	static int STEPS_LEFT_TEXT = 3;
	static int NEW_TERM_CHECK_BOX = 4;
	static int POSITIVE_NEGATIVE_CHECK_BOX = 5;
	static int INVERSE_CHECK_BOX = 6;
	static int UNIT_TYPE_INDICATOR = 7;
	static int PROCEDURE_RECT = 8;
	static int PROCEDURE_INPUT = 9;
	static int PROCEDURE_BACKGROUND = 10;
	static int PROCEDURE_SCOPE = 11;

}
