#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEEDITORCONFIGS(X) \
	X(gridSize) \
	X(visibleGridPointRadiusCount)

namespace components {
	struct EditorConfigs {
		int gridSize = 1;
		int visibleGridPointRadiusCount = 10;

	};

    template<typename V>
    static void reflectEditorConfigs(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<EditorConfigs>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEEDITORCONFIGS(X)
        #undef X
    }
}
