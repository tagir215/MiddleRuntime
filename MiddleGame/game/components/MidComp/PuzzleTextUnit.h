#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPUZZLETEXTUNIT(X)

namespace components {
	struct PuzzleTextUnit {

	};

    template<typename V>
    static void reflectPuzzleTextUnit(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<PuzzleTextUnit>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPUZZLETEXTUNIT(X)
        #undef X
    }
}
