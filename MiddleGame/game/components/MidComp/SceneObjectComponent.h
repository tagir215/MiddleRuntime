#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESCENEOBJECTCOMPONENT(X)

namespace components {
	struct SceneObjectComponent {

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<SceneObjectComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLESCENEOBJECTCOMPONENT(X)
        #undef X
    }
}
