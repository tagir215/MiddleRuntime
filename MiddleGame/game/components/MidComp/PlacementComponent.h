#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPLACEMENTCOMPONENT(X) 

namespace components {
	struct PlacementComponent : public middle::Serializable{
		bool grabbing = true;

	};
}
