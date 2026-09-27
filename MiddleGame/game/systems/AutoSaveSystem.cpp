#pragma once
#include "game_state.h"
#include "middle_system_registrar.h"
#include "component_utils.h"
#include "MidComp/QueuedForSaveTag.h"
#include "alg_file_utils.h"
#include "abstract_ui.h"

class AutoSaveSystem : public middle::MiddleGameplaySystem {
	components::CompCache* cache;

	void init(middle::GameState* gameState) override {
		systemUpdateType = middle::SystemUpdateType::INITFRAME;
		// run after cache update
		updatePriority = 5;

		cache = middle::newCompCache(gameState, systemName);
		cache->addType<components::QueuedForSaveTag>();
	}
	void update(middle::GameState* gameState) override {
		//START_MIDGUI(gameState);
		//midguiBegin("ActiveBubbleName");
		//static char activeBubbleName[128] = "";
		//ImGui::InputText("Equation name", activeBubbleName, IM_ARRAYSIZE(activeBubbleName));
		//if (ImGui::IsItemFocused()) {
		//	middle::insertInputBlock(gameState, middle::InputBlockers::KEYBOARD_BLOCK);
		//	middle::insertInputBlock(gameState, middle::InputBlockers::MOUSE_BLOCK);
		//	gameState->bubbleAlgebraState.activeBubbleName = activeBubbleName;
		//}
		//midguiEnd();

		for (middle::Id id : cache->relevantIdVector) {
			middle::queueComponentDeletion<components::QueuedForSaveTag>(gameState, id);
			//bubequ::saveBubble(gameState, id, gameState->bubbleAlgebraState.activeBubbleName);
		}
	}
};

static middle::SystemRegistrar<AutoSaveSystem> reg("AutoSaveSystem");
