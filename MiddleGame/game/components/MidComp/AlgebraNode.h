#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEALGEBRANODE(X) \
	X(type) \
	X(variableLabel) \
	X(value) \
	X(power) \
	X(isNegative) \
	X(isNegativePower) \
	X(isInversePower)


namespace components {
	struct AlgebraNode {
		int type = middle::UNASSIGNED;
		std::string variableLabel = "";
		float value = 0;
		int power = 1;
		bool isNegative = false;
		bool isNegativePower = false;
		bool isInversePower = false;

	};

	enum class AlgebraNodeType {
		BUBBLE,
		VARIABLE,
		UNIT,
		FRACTION,
		MULTIPLICATION,
		EQUALS,
	};

    template<typename V>
    static void reflectAlgebraNode(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<AlgebraNode>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEALGEBRANODE(X)
        #undef X
    }

}
