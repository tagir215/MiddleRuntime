#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPROCEDURECOMPONENT(X)

namespace components {
	struct ProcedureComponent {

	};

    template<typename V>
    static void reflectProcedureComponent(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<ProcedureComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPROCEDURECOMPONENT(X)
        #undef X
    }
}
