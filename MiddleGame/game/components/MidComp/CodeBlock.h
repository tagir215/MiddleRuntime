#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECODEBLOCK(X) \
	X(type)

namespace components {
	struct CodeBlock {
		int type = 0;
		bool exitLoop = false;

	};
}

namespace codeBlockTypes {
	inline int BLOCK = 0; 
	inline int LOOP_BLOCK = 1;

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<CodeBlock>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLECODEBLOCK(X)
        #undef X
    }
}
