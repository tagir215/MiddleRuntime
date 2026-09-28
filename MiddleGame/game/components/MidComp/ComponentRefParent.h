#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECOMPONENTREFPARENT(X) \
	X(memberIds)

namespace components {
	struct ComponentRefParent : public middle::Serializable{
		std::vector<middle::Id>memberIds;
	};
}
