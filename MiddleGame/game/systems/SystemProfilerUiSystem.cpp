#pragma once
#include "game_state.h"
#include "middle_system_registrar.h"
#include "middle_shape_utils.h"
#include "abstract_ui.h"

using namespace middleUI;

class SystemProfilerUiSystem : public middle::MiddleGameplaySystem {
public:
	SystemProfilerUiSystem() {
		systemUpdateType = middle::SystemUpdateType::RENDERING;
		systemModeType = middle::SystemModeType::ENGINE;
	}

	void init(middle::GameState* gameState) override {
	}

	void drawText(UiBuilder& builder, const MiddleGameplaySystem* sys) {
		if (!sys) {
			return;
		}
		float count = sys->updateTime.count();
		if (count <= 0) {
			return;
		}
		std::string text = sys->systemName + ": " + std::to_string(count) + "ms";
		midguiText(text.c_str());
	}

	void update(middle::GameState* gameState) override {
		START_MIDGUI(gameState);

		midguiBegin("profiler");
		for (auto& sys : gameState->engineSystemInitFrame) {
			drawText(builder, sys.get());
		}
		for (auto& sys : gameState->engineSystemsFrameStart) {
			drawText(builder, sys.get());
		}

		for (auto& pair : gameState->gameplaySystems) {
			drawText(builder, pair.second.get());
		}

		for (auto& pair : gameState->gameplaySystemsPostFrame) {
			drawText(builder, pair.second.get());
		}
		for (auto& sys : gameState->engineRendererSystems) {
			drawText(builder, sys.get());
		}

		midguiEnd();
	}
};

static middle::SystemRegistrar<SystemProfilerUiSystem> reg("SystemProfilerUiSystem");
