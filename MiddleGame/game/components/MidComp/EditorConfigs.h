#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEEDITORCONFIGS(X) \
	X(gridSize) \
	X(visibleGridPointRadiusCount)

namespace components {
	struct EditorConfigs : public middle::Serializable{
		int gridSize = 1;
		int visibleGridPointRadiusCount = 10;

	};
}

