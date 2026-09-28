#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEINVENTORYSLOT(X) \
	X(inventoryIndex) \
	X(slotIndex)

namespace components {
	struct InventorySlot : public middle::Serializable{
		int inventoryIndex = -1;
		int slotIndex = -1;

	};
}
