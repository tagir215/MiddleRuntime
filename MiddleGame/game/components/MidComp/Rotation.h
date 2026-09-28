#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEROTATION(X) \
	X(rotation)

namespace components {
	struct Rotation : public middle::Serializable{
		midMath::Quaternion rotation;

	};

}

namespace middle {
	const midMath::Vector3 ROTATION_FORWARD = { 0,1,0 };
}
