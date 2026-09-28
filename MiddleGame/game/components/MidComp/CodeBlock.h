#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECODEBLOCK(X) \
	X(type)

namespace components {
	struct CodeBlock : public middle::Serializable{
		int type = 0;
		bool exitLoop = false;

	};
}

namespace codeBlockTypes {
	inline int BLOCK = 0; 
	inline int LOOP_BLOCK = 1;
}
