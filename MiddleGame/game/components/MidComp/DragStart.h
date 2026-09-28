#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEDRAGSTART(X) \
	X(dragStartPos)

namespace components {
	struct DragStart {
		midMath::Vector3 dragStartPos;
		midMath::Vector3 gizmoPos;
		midMath::Vector3 axis;
		int axisId;

		midMath::Quaternion initRotation;
		midMath::Vector3 initPosition;
		midMath::Vector3 initScale;

	};

    template<typename V>
    static void reflectDragStart(middle::Shape& shape, V& v) {
        auto comp = middle::getComponent<DragStart>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEDRAGSTART(X)
        #undef X
    }
}
