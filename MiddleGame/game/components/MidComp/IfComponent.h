#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEIFCOMPONENT(X) \
	X(type)

namespace components {
	struct IfComponent : public middle::Serializable{
		int type = 0;

	};
}
