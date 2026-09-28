#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESCALE(X) \
	X(scale)


namespace components {
	struct Scale : public middle::Serializable{
		midMath::Vector3 scale = { 1,1,1 };

	};
}
