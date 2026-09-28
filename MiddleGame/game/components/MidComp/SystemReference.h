#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESYSTEMREFERENCE(X) \
	X(systemName)

namespace components {
	struct SystemReference : public middle::Serializable{
		std::string systemName;

	};
}
