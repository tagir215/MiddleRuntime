#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLELOCALPOSITION(X) \
	X(pos)

namespace components {
	struct LocalPosition : public middle::Serializable{
		midMath::Vector3 pos = { 0,0,0 };

	};
}
