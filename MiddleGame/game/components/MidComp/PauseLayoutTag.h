#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPAUSELAYOUTTAG(X) 

namespace components {
	struct PauseLayoutTag {
		float timeLeft = 0;

	};

    template<typename V>
    static void reflectPauseLayoutTag(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<PauseLayoutTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPAUSELAYOUTTAG(X)
        #undef X
    }
}
