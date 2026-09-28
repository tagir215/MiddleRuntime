#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPROCEDURETARGETTAG(X) 

namespace components {
	struct ProcedureTargetTag {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<ProcedureTargetTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPROCEDURETARGETTAG(X)
        #undef X
    }
}
