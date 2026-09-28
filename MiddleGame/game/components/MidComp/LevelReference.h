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
}

namespace bubbleLevelConstants {
	//std::string folder = "../bubbleData/problems/";

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<LevelReference>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLELEVELREFERENCE(X)
        #undef X
    }
}
