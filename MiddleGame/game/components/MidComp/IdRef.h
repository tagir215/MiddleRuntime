#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEIDREF(X) \
	X(idRef)

namespace components {
	struct IdRef {
		middle::Id idRef;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<IdRef>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEIDREF(X)
        #undef X
    }
}
