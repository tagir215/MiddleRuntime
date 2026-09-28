#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEEDITORTEXT(X) \
	X(text)

namespace components {
	struct EditorText : public middle::Serializable{
		std::string text;

	};
}
