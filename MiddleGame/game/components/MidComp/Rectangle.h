#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLERECTANGLE(X) \
	X(width) \
	X(height)

namespace components {
	struct Rectangle : public middle::Serializable{
		float width = 0;
		float height = 0;

	};
}
