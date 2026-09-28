#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLELOGICGATECONNECTION(X) \
	X(connectionId)

namespace components {
	struct BubbleLogicGateConnection : public middle::Serializable{
		middle::Id connectionId;

	};
}
