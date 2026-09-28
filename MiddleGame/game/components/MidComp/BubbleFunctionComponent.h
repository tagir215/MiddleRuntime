#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEFUNCTIONCOMPONENT(X) \
	X(label)

namespace components {
	struct BubbleFunctionComponent : public middle::Serializable{
		std::string label;

	};
}
