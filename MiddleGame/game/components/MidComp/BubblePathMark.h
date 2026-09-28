#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEPATHMARK(X) 

namespace components {
	struct BubblePathMark : public middle::Serializable{
		size_t stamp = 0;

	};
}
