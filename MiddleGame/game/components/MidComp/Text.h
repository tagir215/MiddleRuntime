#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETEXT(X) \
	X(text) \
	X(fontColorR) \
	X(fontColorG) \
	X(fontColorB) \
	X(fontColorA) \
	X(offsetX) \
	X(offsetY) \
	X(offsetZ) \
	X(fontSize) \
	X(visible) 

namespace components {
	struct Text : public middle::Serializable{
		std::string text = "Text";
		float fontColorR = 255;
		float fontColorG = 255;
		float fontColorB = 255;
		float fontColorA = 255;
		float offsetX = 0;
		float offsetY = 0;
		float offsetZ = 0;
		float fontSize = 1;
		bool visible = true;

	};
}
