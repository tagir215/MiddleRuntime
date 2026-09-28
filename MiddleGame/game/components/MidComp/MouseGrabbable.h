#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
# define MIDDLEMOUSEGRABBABLE(X) 

namespace components {
	struct MouseGrabbable : public middle::Serializable{
		bool grabbing = false;

	};
}
