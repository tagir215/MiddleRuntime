#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEGLOBALRECT(X) \
	X(width) \
	X(height)


namespace components {
	struct GlobalRect : public middle::Serializable{
		float width;
		float height;

	};
}
