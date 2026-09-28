#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEGATECOMPONENT(X) \
	X(status)

namespace components {

	enum BubbleGateStatus {
		CLOSED,
		OPEN,
		DUMMY
	};

	struct BubbleGateComponent : public middle::Serializable{
		int status = BubbleGateStatus::CLOSED;

	};
}
