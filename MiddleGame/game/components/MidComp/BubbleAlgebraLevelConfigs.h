#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEALGEBRALEVELCONFIGS(X) \
	X(allowedMoves) \
	X(levelName) 

namespace components {
	struct BubbleAlgebraLevelConfigs : public middle::Serializable{
		int allowedMoves = 5;
		std::string levelName = "";
		bool initialized = false;

	};
}
