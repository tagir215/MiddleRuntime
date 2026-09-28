#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEINTERSECTINGTAG(X)

namespace components {
	struct IntersectingTag {
		bool intersectingTop = false;
		int framesIntersected = 0;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<IntersectingTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEINTERSECTINGTAG(X)
        #undef X
    }
}
