#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECOLOR(X) \
	X(colorR) \
	X(colorG) \
	X(colorB) \
	X(colorA) \
	

namespace components {
	struct Color {
		float colorR;
		float colorG;
		float colorB;
		float colorA;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Color>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLECOLOR(X)
        #undef X
    }
}
