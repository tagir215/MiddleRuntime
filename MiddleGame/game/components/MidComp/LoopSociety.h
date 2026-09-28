#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define LOOPSOCIETY(X) \
	X(parentLoopId) \
	X(loopMemberIds)

namespace components {
	struct LoopSociety : public middle::Serializable{
		middle::Id parentLoopId;
		std::vector<middle::Id>loopMemberIds;

	};
}
