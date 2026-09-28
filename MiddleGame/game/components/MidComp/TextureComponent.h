#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETEXTURECOMPONENT(X) \
	X(path) \
	X(scale) \
	X(textureType) \
	X(filename) 

namespace middleTextureType {
	inline int BILLBOARD = 0;
	inline int BACKGROUND = 1;
}


namespace components {
	struct TextureComponent : public middle::Serializable {
		std::string path;
		std::string filename;
		float scale = 1;
		int textureType = middleTextureType::BILLBOARD;
		midPrimitive::Texture2D texture;
		bool initialized = false;

	};

}


