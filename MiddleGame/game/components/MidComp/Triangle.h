#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETRIANGLE(X) \
	X(width) \
	X(height)

namespace components {
	struct Triangle : public middle::Serializable{
		float width;
		float height;

	};
}
