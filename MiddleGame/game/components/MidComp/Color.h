#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECOLOR(X) \
	X(colorR) \
	X(colorG) \
	X(colorB) \
	X(colorA) \
	

namespace components {
	struct Color : public middle::Serializable{
		float colorR;
		float colorG;
		float colorB;
		float colorA;

	};
}
