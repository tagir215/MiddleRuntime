#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLELAYER(X) \
	X(layer)


namespace components {
	struct Layer {
		int layer = middle::UNASSIGNED;
	};

    template<typename V>
    static void reflectLayer(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<Layer>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLELAYER(X)
        #undef X
    }
}
