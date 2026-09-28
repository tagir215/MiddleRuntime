#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#include "bubble_actions.h"
#define MIDDLEINPUTVARIABLE(X) \
	X(unitRef) \
	X(rootNodeId) \
	X(startPointNodeId)

namespace components {
	struct InputVariable : public middle::Serializable{
		middle::Id unitRef;
		middle::Id rootNodeId;
		middle::Id startPointNodeId;

	};
}
