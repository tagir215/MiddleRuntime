#pragma once
#include "registrars.h"
#include "editor_file_utils.h"

#define MIDDLEPHYSICSDATA(X) \
	X(mass) \
	X(invMass) \
	X(momentOfInertia) \
	X(velX) \
	X(velY) \
	X(velZ) \
	X(damX) \
	X(damY) \
	X(damZ) \
	X(accX) \
	X(accY) \
	X(accZ) \
	X(infiniteMass) 

namespace components {
	struct PhysicsData {
		float mass = 1;
		float invMass = 1;
		float momentOfInertia = 1;
		float invMomentOfInertia = 1;
		float velX = 0;
		float velY = 0;
		float velZ = 0;
		float damX = 0;
		float damY = 0;
		float damZ = 0;
		float accX = 0;
		float accY = 0;
		float accZ = 0;
		bool infiniteMass = false;

	};

    template<typename V>
    static void reflect(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<PhysicsData>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEPHYSICSDATA(X)
        #undef X
    }
}
