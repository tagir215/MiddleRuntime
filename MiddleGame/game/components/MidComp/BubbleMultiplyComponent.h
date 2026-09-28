#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEMULTIPLYCOMPONENT(X) \
	X(operationType)

namespace components {
	struct BubbleMultiplyComponent : public middle::Serializable{
		int operationType = 0;

	};

}
