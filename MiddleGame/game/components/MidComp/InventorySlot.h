#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEINVENTORYSLOT(X) \
	X(inventoryIndex) \
	X(slotIndex)

namespace components {
	struct InventorySlot {
		int inventoryIndex = -1;
		int slotIndex = -1;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<InventorySlot>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEINVENTORYSLOT(X)
        #undef X
    }
}
