#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEOUTPUTVARIABLE(X) \
	X(unitRef) \
	X(label)

namespace components {
	struct OutputVariable {
		middle::Id unitRef;
		std::string label = "";

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<OutputVariable>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEOUTPUTVARIABLE(X)
        #undef X
    }
}
