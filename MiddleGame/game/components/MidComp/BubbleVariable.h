#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEVARIABLE(X) \
	X(label) \
	X(isNegative)


namespace components {
	struct BubbleVariable : public middle::Serializable{
		std::string label;
		bool isNegative = false;

	};
}
