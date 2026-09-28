#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECONSTRAINT(X) \
	X(idA) \
	X(idB) \
	X(stiffness) \
	X(biasFactor) \
	X(targetDistance) 

namespace components {
	struct Constraint : public middle::Serializable{
		middle::Id idA;
		middle::Id idB;
		float stiffness = 0.8f;
		float biasFactor = 0.8f;;
		float targetDistance;

	};
}
