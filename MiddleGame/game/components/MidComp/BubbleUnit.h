#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEUNIT(X) \
	X(value)

namespace components {
	struct BubbleUnit : public middle::Serializable{
		int value = 1;

	};
}
