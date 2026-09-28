#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECUBOID(X) \
	X(width) \
	X(height) \
	X(length)

namespace components {
	struct Cuboid : public middle::Serializable{
		float width = 0;
		float height = 0;
		float length = 0;

	};
}
