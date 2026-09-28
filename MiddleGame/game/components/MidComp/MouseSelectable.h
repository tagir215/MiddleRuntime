#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEMOUSESELECTABLE(X)

namespace components {
	struct MouseSelectable : public middle::Serializable{
		bool selected = false;

	};
}
