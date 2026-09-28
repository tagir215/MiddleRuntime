#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPOSITION(X) \
	X(posX) \
	X(posY) \
	X(posZ) 

namespace components {
	struct Position : public middle::Serializable{
		float posX;
		float posY;
		float posZ;

	};
}
