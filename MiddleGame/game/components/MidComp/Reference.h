#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEREFERENCE(X) \
	X(sceneName) \
	X(folder)

namespace components {
	struct Reference : public middle::Serializable{
		std::string sceneName;
		std::string folder;

	};
}
