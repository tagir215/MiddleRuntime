#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEINTERSECTINGTAG(X)

namespace components {
	struct IntersectingTag : public middle::Serializable{
		bool intersectingTop = false;
		int framesIntersected = 0;

	};
}
