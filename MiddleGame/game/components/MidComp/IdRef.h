#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEIDREF(X) \
	X(idRef)

namespace components {
	struct IdRef : public middle::Serializable{
		middle::Id idRef;

	};
}
