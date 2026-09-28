#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPROCEDUREUSEUITAG(X)

namespace components {
	struct ProcedureUseUiTag {

	};

    template<typename V>
    static void reflectProcedureUseUiTag(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<ProcedureUseUiTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPROCEDUREUSEUITAG(X)
        #undef X
    }
}
