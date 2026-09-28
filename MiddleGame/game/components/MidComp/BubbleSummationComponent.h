#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLESUMMATIONCOMPONENT(X) 

namespace components {
	enum SummationRole {
		INDEX,
		UPPER_LIMIT,
		SUMMAND
	};

	enum SummationIndexRole {
		INDEX_VARIABLE,
		INDEX_VALUE
	};

	struct BubbleSummationComponent : public middle::Serializable{

	};
}
