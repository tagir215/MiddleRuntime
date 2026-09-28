#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLELOGICGATECONNECTION(X) \
	X(connectionId)

namespace components {
	struct BubbleLogicGateConnection {
		middle::Id connectionId;

	};

    template<typename V>
    static void reflectBubbleLogicGateConnection(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<BubbleLogicGateConnection>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEBUBBLELOGICGATECONNECTION(X)
        #undef X
    }
}
