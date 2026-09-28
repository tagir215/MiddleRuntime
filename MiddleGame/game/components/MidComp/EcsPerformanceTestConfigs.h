#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEECSPERFORMANCETESTCONFIGS(X) \
	X(entityCount)
	

namespace components {
	struct EcsPerformanceTestConfigs : public middle::Serializable{
		int entityCount = 0;

	};
}
