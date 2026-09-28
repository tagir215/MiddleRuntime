#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLELEVELREFERENCE(X) \
	X(levelName) \
	X(complete)

namespace components {
	struct LevelReference : public middle::Serializable{
		std::string levelName = "";
		bool complete = false;

	};
}

namespace bubbleLevelConstants {
	//std::string folder = "../bubbleData/problems/";
}
