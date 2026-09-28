#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESCALE(X) \
	X(scale)


namespace components {
	struct Scale {
		midMath::Vector3 scale = { 1,1,1 };

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Scale>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLESCALE(X)
        #undef X
    }
}
