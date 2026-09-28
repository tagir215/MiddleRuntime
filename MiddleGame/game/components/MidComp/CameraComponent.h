#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLECAMERACOMPONENT(X) \
	X(targetX) \
	X(targetY) \
	X(targetZ) \
	X(upX) \
	X(upY) \
	X(upZ) \
	X(fovy) \
	X(projection) \
	X(active)

namespace components {
	struct CameraComponent : public middle::Serializable{
		float targetX;
		float targetY;
		float targetZ;
		float upX;
		float upY;
		float upZ;
		float fovy;             
		int projection;        
		bool active = false;
		float speedY = 0;
		float speedX = 0;
		float speedZ = 0;


	};
}
