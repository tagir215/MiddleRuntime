#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECOMPONENTREFERENCE(X) \
	X(componentName)

namespace components {
	struct ComponentReference : public middle::Serializable{
		std::string componentName;

	};
}
