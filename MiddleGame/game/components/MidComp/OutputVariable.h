#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEOUTPUTVARIABLE(X) \
	X(unitRef) \
	X(label)

namespace components {
	struct OutputVariable : public middle::Serializable{
		middle::Id unitRef;
		std::string label = "";

	};
}
