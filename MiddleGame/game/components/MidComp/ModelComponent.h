#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEMODELCOMPONENT(X) \
	X(path)

namespace components {
	struct ModelComponent : public middle::Serializable{
		std::string path;
		midPrimitive::Model model;
		bool initialized = false;

	};
}
