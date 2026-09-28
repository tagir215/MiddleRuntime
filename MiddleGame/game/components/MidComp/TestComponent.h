#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETESTCOMPONENT(X) \
	X(vec) 


namespace components {
	struct TestComponent {
		midMath::Vector3 vec;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<TestComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLETESTCOMPONENT(X)
        #undef X
    }
}
