#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEVISIBILITYCOMPONENT(X) \
	X(visible)

namespace components {
	struct VisibilityComponent : public middle::Serializable{
		bool visible = true;

	};
}
