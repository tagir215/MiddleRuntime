#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define LOOPSOCIETY(X) \
	X(parentLoopId) \
	X(loopMemberIds)

namespace components {
	struct LoopSociety {
		middle::Id parentLoopId;
		std::vector<middle::Id>loopMemberIds;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<LoopSociety>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLELOOPSOCIETY(X)
        #undef X
    }
}
