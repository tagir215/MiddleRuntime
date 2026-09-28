#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPUZZLETEXTPANEL(X) 

namespace components {
	struct PuzzleTextPanel {

	};

    template<typename V>
    static void reflectPuzzleTextPanel(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<PuzzleTextPanel>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPUZZLETEXTPANEL(X)
        #undef X
    }
}
