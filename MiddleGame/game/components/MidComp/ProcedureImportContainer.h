#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPROCEDUREIMPORTCONTAINER(X) \
	X(bubbleRef)

namespace components {
	struct ProcedureImportContainer {
		std::string loadedProcedureName = "";
		middle::Id bubbleRef;

	};

    template<typename V>
    static void reflectProcedureImportContainer(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<ProcedureImportContainer>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPROCEDUREIMPORTCONTAINER(X)
        #undef X
    }
}
