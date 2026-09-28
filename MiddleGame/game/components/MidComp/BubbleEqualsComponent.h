#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEEQUALSCOMPONENT(X)

namespace components {

	enum BubbleEqualsRole {
		EQUALS_LEFT,
		EQUALS_RIGHT
	};

	struct BubbleEqualsComponent : public middle::Serializable{

	};
}
