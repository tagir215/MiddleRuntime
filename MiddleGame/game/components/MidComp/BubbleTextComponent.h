#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLETEXTCOMPONENT(X) \
	X(textName) 

namespace components {
	struct BubbleTextComponent : public middle::Serializable{
		std::string textName;
		std::string text;
		float fontSize;

	};
}
