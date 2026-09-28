#pragma once
#include "game_state.h"
#include "middle_system_registrar.h"
#include "alg_file_utils.h"
#include "bubble_paths.h"
#include "equlab_actions.h"
#include "middle_shape_utils.h"
#include "bubble_utils.h"
#include "MidComp/PuzzleTextUnit.h"
#include "MidComp/Text.h"
#include "MidComp/GlobalTransform.h"
#include "MidComp/UiComponent.h"
#include "MidComp/PuzzleTextPanel.h"
#include "MidComp/Rectangle.h"
#include "MidComp/LoopTag.h"
#include "MidComp/Layer.h"
#include "MidComp/SceneObjectComponent.h"
#include "MidComp/TopDogBubbleTag.h"
#include "MidComp/LocalPosition.h"
#include "MidComp/LocalScale.h"
#include "bubequ_mapping.h"
#include "MidComp/IntersectingTag.h"
#include "bubble_actions.h"
#include "midconfig.h"


class WriterUnBlockingSystem : public middle::MiddleGameplaySystem {
	components::CompCache* textCache;

	void init(middle::GameState* gameState) override {
		textCache = middle::newCompCache(gameState, systemName);
		textCache->addType<components::BubbleTextComponent>();
		textCache->addType<components::IntersectingTag>();
	}

	void update(middle::GameState* gameState) override {
	}
};

static middle::SystemRegistrar<WriterUnBlockingSystem> reg("WriterUnBlockingSystem");
