#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEGLOBALRADIUS(X) \
	X(radius)

namespace components {
	struct GlobalRadius : public middle::Serializable{
		float radius;

	};
}
