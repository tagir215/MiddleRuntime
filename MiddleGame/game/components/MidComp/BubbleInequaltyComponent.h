#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEINEQUALTYCOMPONENT(X) 

namespace components {
	enum InequaltyRole {
		INEQUAL_LESSER,
		INEQUAL_GREATER
	};

	struct BubbleInequaltyComponent : public middle::Serializable {
	};
}
