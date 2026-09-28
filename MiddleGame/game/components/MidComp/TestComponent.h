#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLETESTCOMPONENT(X) \
	X(vec) 


namespace components {
	struct TestComponent : public middle::Serializable{
		midMath::Vector3 vec;

	};
}
