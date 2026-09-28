#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEECSPERFORMANCETESTCONFIGS(X) \
	X(entityCount)
	

namespace components {
	struct EcsPerformanceTestConfigs {
		int entityCount = 0;

	};

    template<typename V>
    static void reflectEcsPerformanceTestConfigs(middle::MiddleMan& shape, V& v) {
        auto comp = middle::getComponent<EcsPerformanceTestConfigs>(shape);
        #define X(f) v(#f, comp->f);
            MIDDLEECSPERFORMANCETESTCONFIGS(X)
        #undef X
    }
}
