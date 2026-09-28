#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEDELETECOMPONENT(X) 

namespace components {
	struct DeleteComponent : public middle::Serializable{
		int framesUntilDelete = 0;
	};
}
