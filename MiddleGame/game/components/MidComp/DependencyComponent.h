#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEDEPENDENCYCOMPONENT(X) \
	X(idRef)

namespace components {
	struct DependencyComponent : public middle::Serializable{
		middle::Id idRef;

	};
}
