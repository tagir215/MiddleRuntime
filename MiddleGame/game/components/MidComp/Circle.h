#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECIRCLE(X) \
	X(radius)

namespace components {
	struct Circle : public middle::Serializable{
		float radius;

	};
}
