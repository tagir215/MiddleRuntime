#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLELAYER(X) \
	X(layer)


namespace components {
	struct Layer : public middle::Serializable{
		int layer = middle::UNASSIGNED;
	};
}
