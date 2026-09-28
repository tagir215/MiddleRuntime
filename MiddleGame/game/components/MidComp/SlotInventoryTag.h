#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESLOTINVENTORYTAG(X) \
	X(type)

namespace components {
	struct SlotInventoryTag {
		int type = middle::UNASSIGNED;

	};

    template<typename V>
    static void reflectSlotInventoryTag(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<SlotInventoryTag>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLESLOTINVENTORYTAG(X)
        #undef X
    }
}
