#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEBUBBLEEQUALSVARIABLE(X) 

namespace components {
	struct BubbleEqualsVariable : public middle::Serializable{
		std::string variableLabel;
		bool wantsToReplaceVariable = false;
		bool wantsToReplaceBubble = false;
		middle::Id matchingIdRef;

	};
}
