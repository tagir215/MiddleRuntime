#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPROCEDUREIMPORTCONTAINER(X) \
	X(bubbleRef)

namespace components {
	struct ProcedureImportContainer : public middle::Serializable{
		std::string loadedProcedureName = "";
		middle::Id bubbleRef;

	};
}
