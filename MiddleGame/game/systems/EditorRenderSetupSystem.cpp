#pragma once
#include "game_state.h"
#include "middle_system_registrar.h"
#include "middle_shape_utils.h"
#include "MidComp/Sphere.h"
#include "MidComp/GlobalTransform.h"
#include "MidComp/Constraint.h"
#include "MidComp/PhysicsData.h"
#include "MidComp/Color.h"
#include "MidComp/MouseSelectable.h"
#include "MidComp/MouseGrabbable.h"
#include "MidComp/MouseIntersectable.h"
#include "MidComp/LoopSociety.h"
#include "JointEntity.h"
#include "LoopEntity.h"
#include "ConstraintEntity.h"
#include "MidComp/LoopTag.h"
#include "MidComp/Reference.h"
#include "MidComp/SystemReference.h"
#include "MidComp/ComponentReference.h"
#include "MidComp/EditorText.h"
#include "MidComp/HiddenTag.h"
#include "MidComp/ConfigComponent.h"
#include "MidComp/EditorConfigs.h"
#include "middle_math.h"
#include "MidComp/Position.h"
#include "component_utils.h"
#include "MidComp/IntersectingTag.h"

class EditorRenderSetupSystem : public middle::MiddleGameplaySystem {
public:
	EditorRenderSetupSystem() {
		systemUpdateType = middle::SystemUpdateType::RENDERING;
		systemModeType = middle::SystemModeType::EDITOR;
	}

	components::CompCache* nodeCache;

	void init(middle::GameState* gameState) {
		nodeCache = middle::newCompCache(gameState, systemName);
		nodeCache->addType<components::GlobalTransform>();
		nodeCache->addType<components::HiddenTag>(components::NOTINTERESTED);
	}

	void setTransform(middle::RenderData& data, int index, const components::GlobalTransform* transform) {
		data.positionsX[index] = transform->pos.x;
		data.positionsY[index] = transform->pos.y;
		data.positionsZ[index] = transform->pos.z;
		data.rotationsX[index] = transform->rotation.x;
		data.rotationsY[index] = transform->rotation.y;
		data.rotationsZ[index] = transform->rotation.z;
		data.rotationsW[index] = transform->rotation.w;
		data.scalesX[index] = transform->scale.x;
		data.scalesY[index] = transform->scale.y;
		data.scalesZ[index] = transform->scale.z;
	}

	void update(middle::GameState* gameState) override {

		if (gameState->middleState.applicationMode != middle::ApplicationMode::EDITOR_MODE) {
			return;
		}

		auto nodeIt = nodeCache->begin<components::GlobalTransform>();
		auto& renderData = gameState->middleState.newRenderData;
		auto transformIt = nodeCache->begin<components::GlobalTransform>();
		for (middle::Id id : nodeCache->relevantIdVector) {
			auto transform = *transformIt;
			size_t manIndex = middle::pushNextRenderObject(gameState);
			renderData.types[manIndex] = middle::RenderObjectType::MIDDLE_MAN;
			setTransform(renderData, manIndex, transform);

			size_t textIndex = middle::pushNextRenderObject(gameState);
			renderData.types[textIndex] = middle::RenderObjectType::EDITOR_TEXT;
			setTransform(renderData, textIndex, transform);
			const float textOffsetZ = 5;
			renderData.positionsZ[textIndex] += textOffsetZ;
			static const char* text = "MiddleMan";
			renderData.texts[textIndex] = text;
		}
	}
};

static middle::SystemRegistrar<EditorRenderSetupSystem> reg("EditorRenderSetupSystem");
