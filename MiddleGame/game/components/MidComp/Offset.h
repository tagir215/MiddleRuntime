#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEOFFSET(X) \
	X(offsetX) \
	X(offsetY) \
	X(offsetZ) 

namespace components {
	struct Offset : public middle::Serializable{
		float offsetX = 0;
		float offsetY = 0;
		float offsetZ = 0;

	};
}
