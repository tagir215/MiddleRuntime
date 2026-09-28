#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESLOTINVENTORYTAG(X) \
	X(type)

namespace components {
	struct SlotInventoryTag : public middle::Serializable{
		int type = middle::UNASSIGNED;

	};
}
