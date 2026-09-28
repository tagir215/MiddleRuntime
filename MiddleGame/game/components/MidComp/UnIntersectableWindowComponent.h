#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEUNINTERSECTABLEWINDOWCOMPONENT(X) 

namespace components {
	struct UnIntersectableWindowComponent : public middle::Serializable{
		float timeLeft = 0;

	};
}
