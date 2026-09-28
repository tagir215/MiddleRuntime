#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLELEVELREFERENCE(X) \
	X(levelName) \
	X(complete)

namespace components {
	struct LevelReference {
		std::string levelName = "";
		bool complete = false;

	};

    template<typename V>
    static void reflectLevelReference(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<LevelReference>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLELEVELREFERENCE(X)
        #undef X
    }
}

