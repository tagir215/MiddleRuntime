#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLESPHERE(X) \
	X(radius)

namespace components {
	struct Sphere {
		float radius;
	};

	template<typename V>
	static void reflectSphere(middle::MiddleMan& shape, V& v) {
		auto comp = middle::getComponent<Sphere>(shape);
#define X(f) v(#f, comp->f);
		MIDDLESPHERE(X)
#undef X
	}
}
