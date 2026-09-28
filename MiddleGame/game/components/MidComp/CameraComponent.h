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
	struct CameraComponent {
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

    template<typename V>
    static void reflectCameraComponent(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<CameraComponent>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLECAMERACOMPONENT(X)
        #undef X
    }
}
