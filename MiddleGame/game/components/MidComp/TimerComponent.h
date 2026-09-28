#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETIMERCOMPONENT(X) \
	X(timeLeft)

namespace components {
	struct TimerComponent : public middle::Serializable{
		float timeLeft = 0;

	};
}
