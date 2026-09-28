#pragma once
#include "registrars.h"
#include "editor_file_utils.h"
#define MIDDLEPAUSELAYOUTTAG(X) 

namespace components {
	struct PauseLayoutTag : public middle::Serializable{
		float timeLeft = 0;

	};
}
