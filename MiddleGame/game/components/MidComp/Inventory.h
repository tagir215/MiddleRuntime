#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEINVENTORY(X) \
	X(maxSize)

namespace components {
	enum InventoryInsertType {
		INSERT_ADD,
		INSERT_MULTIPLY,
		INSERT_POWER
	};
	enum InventoryInvariantType {
		X_OVER_X,
		X_MINUS_X
	};
	struct Inventory {
		int maxSize = 5;
		int activeIndex = 0;
		bool invert = false;
		bool negate = false;
		InventoryInsertType insertType;
		InventoryInvariantType invariantType;
		

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<Inventory>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEINVENTORY(X)
        #undef X
    }
}
