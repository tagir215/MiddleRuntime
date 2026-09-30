#pragma once
#include "game_state.h"
#include "middle_system_registrar.h"
#include "middle_shape_utils.h"
#include "middle_component_table.h"
#include "MidComp/BubbleComponent.h"
#include "MidComp/BubbleMultiplyComponent.h"
#include "MidComp/Sphere.h"
#include "MidComp/BubbleUnit.h"
#include "MidComp/FractionalComponent.h"
#include "MidComp/LoopSociety.h"
#include "MidComp/IntersectingTag.h"
#include "bubble_utils.h"
#include "MidComp/BubbleRef.h"
#include "MidComp/Circle.h"
#include "MidComp/Cuboid.h"
#include "MidComp/BubbleEqualsComponent.h"
#include "MidComp/BubbleVariable.h"
#include "bubble_colors.h"
#include "MidComp/Layer.h"
#include "MidComp/GlobalRect.h"
#include "MidComp/UiComponent.h"
#include "MidComp/TextureComponent.h"
#include "MidComp/RuntimeHiddenTag.h"
#include "MidComp/ActiveCheckBoxTag.h"
#include "MidComp/InputVariable.h"
#include "MidComp/ProcedureInputVariable.h"
#include "MidComp/ProcedureContainer.h"
#include "MidComp/CodeBlock.h"
#include "MidComp/IdRef.h"
#include "MidComp/UnIntersectableWindowComponent.h"
#include "MidComp/ActiveSceneEditableTag.h"
#include "MidComp/GlobalTransform.h"
#include "component_utils.h"
#include "MidComp/LocalPosition.h"
#include "MidComp/LocalScale.h"
#include "MidComp/BubblePowerComponent.h"
#include "MidComp/BubbleInequaltyComponent.h"
#include "MidComp/BubbleFunctionComponent.h"
#include "MidComp/GlobalRect.h"
#include "MidComp/BubbleSummationComponent.h"
#include "bubble_paths.h"
#include "MidComp/BubbleTextComponent.h"
#include "MidComp/BubbleSwapComponent.h"
#include "MidComp/BubbleLogicComponent.h"
#include "MidComp/BubbleGateComponent.h"
#include "MidComp/InViewTag.h"
#include "MidComp/BubbleLockedComponent.h"
#include "MidComp/BubbleManipulatable.h"
#include "asset_enums.h"


class BubbleRenderSetup : public middle::MiddleGameplaySystem {
public:

	BubbleRenderSetup() {
		systemModeType = middle::SystemModeType::ENGINE;
		systemUpdateType = middle::SystemUpdateType::RENDERING;
	}

	components::CompCache* bubbleCache;
	components::CompCache* mulCache;
	components::CompCache* variableCache;
	components::CompCache* equalsCache;
	components::CompCache* nonManipulatableEqualsCache;
	components::CompCache* inequCache;
	components::CompCache* unitCache;
	components::CompCache* activeBubbleCache;
	components::CompCache* powerCache;
	components::CompCache* functionCache;
	components::CompCache* summationCache;
	components::CompCache* textCache;
	components::CompCache* swapCache;
	components::CompCache* logicCache;
	components::CompCache* gateCache;

			const float scaleCorrection = 10.2f;

	void init(middle::GameState* gameState) {
		bubbleCache = middle::newCompCache(gameState, systemName);
		bubbleCache->addType<components::BubbleComponent>();
		bubbleCache->addType<components::InViewTag>();
		bubbleCache->addType<components::GlobalRect>();
		bubbleCache->addType<components::Layer>();
		bubbleCache->addType<components::LoopSociety>();
		bubbleCache->addType<components::GlobalTransform>();
		bubbleCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubblePowerComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleSummationComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleFunctionComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleMultiplyComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleInequaltyComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleLogicComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleTextComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleVariable>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleSwapComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleUnit>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleEqualsComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleGateComponent>(components::NOTINTERESTED);
		bubbleCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		bubbleCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		unitCache = middle::newCompCache(gameState, systemName);
		unitCache->addType<components::BubbleUnit>();
		unitCache->addType<components::InViewTag>();
		unitCache->addType<components::Layer>();
		unitCache->addType<components::GlobalTransform>();
		unitCache->addType<components::GlobalRect>();
		unitCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		unitCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		mulCache = middle::newCompCache(gameState, systemName);
		mulCache->addType<components::BubbleMultiplyComponent>();
		mulCache->addType<components::InViewTag>();
		mulCache->addType<components::LoopSociety>();
		mulCache->addType<components::GlobalTransform>();
		mulCache->addType<components::GlobalRect>();
		mulCache->addType<components::Layer>();
		mulCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		mulCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		variableCache = middle::newCompCache(gameState, systemName);
		variableCache->addType<components::BubbleComponent>();
		variableCache->addType<components::InViewTag>();
		variableCache->addType<components::Layer>();
		variableCache->addType<components::BubbleVariable>();
		variableCache->addType<components::GlobalRect>();
		variableCache->addType<components::GlobalTransform>();
		variableCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		variableCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		nonManipulatableEqualsCache = middle::newCompCache(gameState, systemName);
		nonManipulatableEqualsCache->addType<components::BubbleEqualsComponent>();
		nonManipulatableEqualsCache->addType<components::InViewTag>();
		nonManipulatableEqualsCache->addType<components::Layer>();
		nonManipulatableEqualsCache->addType<components::GlobalRect>();
		nonManipulatableEqualsCache->addType<components::GlobalTransform>();
		nonManipulatableEqualsCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		nonManipulatableEqualsCache->addType<components::BubbleManipulatable>(components::NOTINTERESTED);
		nonManipulatableEqualsCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		equalsCache = middle::newCompCache(gameState, systemName);
		equalsCache->addType<components::BubbleEqualsComponent>();
		equalsCache->addType<components::InViewTag>();
		equalsCache->addType<components::Layer>();
		equalsCache->addType<components::GlobalRect>();
		equalsCache->addType<components::GlobalTransform>();
		equalsCache->addType<components::BubbleManipulatable>();
		equalsCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		equalsCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);

		inequCache = middle::newCompCache(gameState, systemName);
		inequCache->addType<components::BubbleInequaltyComponent>();
		inequCache->addType<components::InViewTag>();
		inequCache->addType<components::Layer>();
		inequCache->addType<components::GlobalRect>();
		inequCache->addType<components::GlobalTransform>();
		inequCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		inequCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		activeBubbleCache = middle::newCompCache(gameState, systemName);
		activeBubbleCache->addType<components::ActiveSceneSelectableTag>();
		activeBubbleCache->addType<components::InViewTag>();
		activeBubbleCache->addType<components::GlobalTransform>();
		activeBubbleCache->addType<components::GlobalRect>();
		activeBubbleCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		activeBubbleCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		powerCache = middle::newCompCache(gameState, systemName);
		powerCache->addType<components::BubblePowerComponent>();
		powerCache->addType<components::InViewTag>();
		powerCache->addType<components::GlobalRect>();
		powerCache->addType<components::LoopSociety>();
		powerCache->addType<components::GlobalTransform>();
		powerCache->addType<components::Layer>();
		powerCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		powerCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		functionCache = middle::newCompCache(gameState, systemName);
		functionCache->addType<components::BubbleFunctionComponent>();
		functionCache->addType<components::InViewTag>();
		functionCache->addType<components::GlobalTransform>();
		functionCache->addType<components::Layer>();
		functionCache->addType<components::GlobalRect>();
		functionCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		functionCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		summationCache = middle::newCompCache(gameState, systemName);
		summationCache->addType<components::BubbleSummationComponent>();
		summationCache->addType<components::InViewTag>();
		summationCache->addType<components::Layer>();
		summationCache->addType<components::GlobalRect>();
		summationCache->addType<components::GlobalTransform>();
		summationCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		summationCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		textCache = middle::newCompCache(gameState, systemName);
		textCache->addType<components::BubbleTextComponent>();
		textCache->addType<components::InViewTag>();
		textCache->addType<components::GlobalTransform>();
		textCache->addType<components::GlobalRect>();
		textCache->addType<components::Layer>();
		textCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		textCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		logicCache = middle::newCompCache(gameState, systemName);
		logicCache->addType<components::BubbleLogicComponent>();
		logicCache->addType<components::InViewTag>();
		logicCache->addType<components::GlobalTransform>();
		logicCache->addType<components::GlobalRect>();
		logicCache->addType<components::Layer>();
		logicCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		logicCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
		gateCache = middle::newCompCache(gameState, systemName);
		gateCache->addType<components::BubbleGateComponent>();
		gateCache->addType<components::InViewTag>();
		gateCache->addType<components::GlobalTransform>();
		gateCache->addType<components::GlobalRect>();
		gateCache->addType<components::Layer>();
		gateCache->addType<components::RuntimeHiddenTag>(components::NOTINTERESTED);
		gateCache->addType<components::BubbleLockedComponent>(components::NOTINTERESTED);
	}
	bool debugRendering = false;


	int getCircleSlices(components::GlobalTransform* transform) {
		int slices = (int)(transform->scale.x * 30);
		const int maxSlices = 200;
		const int minSlices = 10;
		slices = slices > minSlices ? slices : minSlices;
		slices = slices < maxSlices ? slices : maxSlices;
		return slices;
	}

	void setTransform(middle::RenderItem& item, components::GlobalTransform* transform) {
		item.transform.translation = transform->pos;
		item.transform.scale = transform->scale;
		item.transform.rotation = transform->rotation;
	}

	enum class LabelPos {
		LEFT,
		CENTER,
		RIGHT
	};

	enum class IconPos {
		CENTER,
		TOP
	};

	int getLayer(middle::GameState* gameState, components::Layer* layer) const{
		return layer->layer - gameState->bubbleAlgebraState.traversePath.size();
	}

	int getLayerYOffset(int layer) {
		const float layerGap = -1.0f;
		return layerGap * layer;
	}

//	void renderBubbleLabel(middle::GameState* gameState, components::GlobalTransform* transform, float height, 
//		const std::string& label, int layer, LabelPos pos, const Color& color) {
//		middle::RenderItem text;
//		text.type = middle::RenderItemType::TEXT;
//		text.text = label;
//		text.color = color;
//		const float labelFontSize = 20;
//		const float offsetFactor = 0.1f;
//		float offset = height * offsetFactor * transform->scale.z;
//		float axis = height * 0.5f * transform->scale.z;
//		text.fontSize = labelFontSize;
//		if(pos == LabelPos::LEFT)
//			text.transform.translation = transform->pos + midMath::Vector3{ -axis + offset,0, axis - offset };
//		else if (pos == LabelPos::CENTER)
//			text.transform.translation = transform->pos + midMath::Vector3{ 0,0, axis - offset };
//		else if (pos == LabelPos::RIGHT)
//			text.transform.translation = transform->pos + midMath::Vector3{ axis + offset, axis - offset };
//		text.transform.translation.y += getLayerYOffset(layer);
//		text.transform.scale = transform->scale;
//		text.transform.rotation = transform->rotation;
//		middle::queueForRender(gameState, text);
//	}

	void renderBubbleIcon(middle::GameState* gameState, components::GlobalTransform* transform, float height, 
		const middleAssets::TEXTURE iconTexture, int layer, IconPos pos) {

		middle::RenderItem icon;
		icon.type = middle::RenderItemType::BILLBOARD;
		icon.shader = middleAssets::BUBBLE_SHADER;
		icon.texture = iconTexture;
		setTransform(icon, transform);
		icon.transform.scale.x *= scaleCorrection;
		icon.transform.scale.y *= scaleCorrection;
		icon.transform.scale.z *= scaleCorrection;
		icon.transform.translation.y += getLayerYOffset(layer);

		const float offsetFactor = 0.1f;
		float offset = height * offsetFactor * transform->scale.z;
		float axis = height * 0.5f * transform->scale.z;


		icon.transform.scale = transform->scale;
		if (pos == IconPos::TOP)
			icon.transform.translation = transform->pos + midMath::Vector3{ 0,0, axis - offset };
		else if (pos == IconPos::CENTER) {
			icon.transform.translation = transform->pos + midMath::Vector3{ 0,0,0 };
			const float centerScaleMultiplier = 4;
			icon.transform.scale = Vector3Scale(transform->scale, centerScaleMultiplier);
		}
		icon.transform.rotation = transform->rotation;
		middle::queueForRender(gameState, icon);
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


	size_t renderBubble(middle::GameState* gameState, middle::RenderObjectType type, int layer, components::GlobalTransform* transform, components::GlobalRect* rect) {
		auto& data = gameState->middleState.newRenderData;
		size_t bubbleIndex = middle::pushNextRenderObject(gameState);
		data.types[bubbleIndex] = type;
		setTransform(data, bubbleIndex, transform);
		data.positionsY[bubbleIndex] += getLayerYOffset(layer);
		data.scalesX[bubbleIndex] = rect->width;
		data.scalesZ[bubbleIndex] = rect->height;
		return bubbleIndex;
	}


	void update(middle::GameState* gameState) override {

		auto bubbleRectIt = bubbleCache->begin<components::GlobalRect>();
		auto bubbleLayerIt = bubbleCache->begin<components::Layer>();
		auto bubbleTransform = bubbleCache->begin<components::GlobalTransform>();
		for (int i = 0; i < bubbleCache->getSize(); ++i) {
			auto rect = *bubbleRectIt;
			auto layer = *bubbleLayerIt;
			auto transform = *bubbleTransform;
			renderBubble(gameState, middle::RenderObjectType::ADDITION_RECT, getLayer(gameState, layer), transform, rect);
		}

		auto logicLayerIt = logicCache->begin<components::Layer>();
		auto logicTransformIt = logicCache->begin<components::GlobalTransform>();
		auto logicRectIt = logicCache->begin<components::GlobalRect>();
		for (middle::Id id : logicCache->relevantIdVector) {
			auto layer = *logicLayerIt;
			auto transform = *logicTransformIt;
			auto rect = *logicRectIt;
			renderBubble(gameState, middle::RenderObjectType::AND_LOGIC_GATE_RECT, getLayer(gameState, layer), transform, rect);
		}

		auto gateLayerIt = gateCache->begin<components::Layer>();
		auto gateTransformIt = gateCache->begin<components::GlobalTransform>();
		auto gateRectIt = gateCache->begin<components::GlobalRect>();
		auto gateIt = gateCache->begin<components::BubbleGateComponent>();
		for (middle::Id id : gateCache->relevantIdVector) {
			auto layer = *gateLayerIt;
			auto transform = *gateTransformIt;
			auto rect = *gateRectIt;
			auto gate = *gateIt;
			renderBubble(gameState, middle::RenderObjectType::GATE_RECT, getLayer(gameState, layer), transform, rect);
		}

		// renderunits
		auto unitIt = unitCache->begin<components::BubbleUnit>();
		auto unitLayerIt = unitCache->begin<components::Layer>();
		auto unitTransformIt = unitCache->begin<components::GlobalTransform>();
		auto unitRectIt = unitCache->begin<components::GlobalRect>();
		for (middle::Id id : unitCache->relevantIdVector) {
			auto unit = *unitIt;
			auto layer = *unitLayerIt;
			auto transform = *unitTransformIt;
			auto rect = *unitRectIt;
			size_t unitIndex =renderBubble(gameState, middle::RenderObjectType::UNIT_RECT, getLayer(gameState, layer), transform, rect);
			auto& data = gameState->middleState.newRenderData;
			if (unit->value > 0) {
				data.texts[unitIndex] = "1";
				data.states[unitIndex] = middle::RenderObjectState::POSITIVE;
			}
			else {
				data.texts[unitIndex] = "-1";
				data.states[unitIndex] = middle::RenderObjectState::NEGATIVE;
			}
		}

		auto textIt = textCache->begin<components::BubbleTextComponent>();
		auto textTransformIt = textCache->begin<components::GlobalTransform>();
		auto textLayerIt = textCache->begin<components::Layer>();
		auto textRectIt = textCache->begin<components::GlobalRect>();
		for (middle::Id id : textCache->relevantIdVector) {
			auto text = *textIt;
			auto layer = *textLayerIt;
			auto transform = *textTransformIt;
			auto rect = *textRectIt;
			size_t index = renderBubble(gameState, middle::RenderObjectType::TEXT_RECT, getLayer(gameState, layer), transform, rect);
			auto& data = gameState->middleState.newRenderData;
			data.texts[index] = text->text.c_str();
		}

		// render variables
		auto variableIt = variableCache->begin<components::BubbleVariable>();
		auto variableBubbleIt = variableCache->begin<components::BubbleComponent>();
		auto variableRectIt = variableCache->begin<components::GlobalRect>();
		auto layerIt = variableCache->begin<components::Layer>();
		auto varTransformIt = variableCache->begin<components::GlobalTransform>();
		for (middle::Id id : variableCache->relevantIdVector) {
			auto variable = *variableIt;
			auto layer = *layerIt;
			auto rect = *variableRectIt;
			auto transform = *varTransformIt;
			size_t index = renderBubble(gameState, middle::RenderObjectType::VARIABLE_RECT, getLayer(gameState, layer), transform, rect);
			auto& data = gameState->middleState.newRenderData;
			if (variable->isNegative) {
				data.states[index] = middle::RenderObjectState::NEGATIVE;
				data.texts[index] = ("-" + variable->label).c_str();
			}
			else{
				data.states[index] = middle::RenderObjectState::POSITIVE;
				data.texts[index] = variable->label.c_str();
			}
		}


		// render muls
		auto mulIt = mulCache->begin<components::BubbleMultiplyComponent>();
		auto mulRectIt = mulCache->begin<components::GlobalRect>();
		auto mulTransformIt = mulCache->begin<components::GlobalTransform>();
		auto mulLayerIt = mulCache->begin<components::Layer>();
		for (middle::Id id : mulCache->relevantIdVector) {
			auto multiplyComponent = *mulIt;
			auto rect = *mulRectIt;
			auto transform = *mulTransformIt;
			auto layer = *mulLayerIt;
			renderBubble(gameState, middle::RenderObjectType::MULTIPLICATION_RECT, getLayer(gameState, layer), transform, rect);
		}

		// renderPowers
		auto powerRectIt = powerCache->begin<components::GlobalRect>();
		auto powerTransformIt = powerCache->begin<components::GlobalTransform>();
		auto powerLayerIt = powerCache->begin<components::Layer>();
		for (middle::Id powerId : powerCache->relevantIdVector) {
			auto rect = *powerRectIt;
			auto transform = *powerTransformIt;
			auto layer = *powerLayerIt;
			renderBubble(gameState, middle::RenderObjectType::POWER_RECT, getLayer(gameState, layer), transform, rect);
		}

		auto equTransformIt = equalsCache->begin<components::GlobalTransform>();
		auto equCircleIt = equalsCache->begin<components::GlobalRect>();
		auto equLayerIt = equalsCache->begin<components::Layer>();
		for (middle::Id id : equalsCache->relevantIdVector) {
			auto transform = *equTransformIt;
			auto rect = *equCircleIt;;
			auto layer = *equLayerIt;
			size_t index = renderBubble(gameState, middle::RenderObjectType::EQUALS_RECT, getLayer(gameState, layer), transform, rect);
			auto& data = gameState->middleState.newRenderData;
			data.states[index] = middle::RenderObjectState::EQUALS_MANIPULATABLE;
		}

		// dimmer equals that cant be modified...
		auto nonEquTransformIt = nonManipulatableEqualsCache->begin<components::GlobalTransform>();
		auto nonEquCircleIt = nonManipulatableEqualsCache->begin<components::GlobalRect>();
		auto nonEquLayerIt = nonManipulatableEqualsCache->begin<components::Layer>();
		for (middle::Id id : nonManipulatableEqualsCache->relevantIdVector) {
			auto transform = *nonEquTransformIt;
			auto rect = *nonEquCircleIt;;
			auto layer = *nonEquLayerIt;
			size_t index = renderBubble(gameState, middle::RenderObjectType::EQUALS_RECT, getLayer(gameState, layer), transform, rect);
			auto& data = gameState->middleState.newRenderData;
			data.states[index] = middle::RenderObjectState::EQUALS_NOT_MANIPULATABLE;
		}

		auto inequTransformIt = inequCache->begin<components::GlobalTransform>();
		auto inequRectIt = inequCache->begin<components::GlobalRect>();
		auto inequLayerIt = inequCache->begin<components::Layer>();
		for (middle::Id id : inequCache->relevantIdVector) {
			auto transform = *inequTransformIt;
			auto rect = *inequRectIt;
			auto layer = *inequLayerIt;
			size_t index = renderBubble(gameState, middle::RenderObjectType::GREATER_RECT, getLayer(gameState, layer), transform, rect);
		}

		auto functionTransformIt = functionCache->begin<components::GlobalTransform>();
		auto functionIt = functionCache->begin<components::BubbleFunctionComponent>();
		auto functionRectIt = functionCache->begin<components::GlobalRect>();
		auto functionLayerIt = functionCache->begin<components::Layer>();
		for (middle::Id id : functionCache->relevantIdVector) {
			// render functionlabel
			auto transform = *functionTransformIt;
			auto rect = *functionRectIt;
			auto func = *functionIt;
			auto layer = *functionLayerIt;
			size_t index = renderBubble(gameState, middle::RenderObjectType::FUNCTION_RECT, getLayer(gameState, layer), transform, rect);
			auto& data = gameState->middleState.newRenderData;
			data.texts[index] = func->label.c_str();
		}

		auto summationTransformIt = summationCache->begin<components::GlobalTransform>();
		auto summationRectIt = summationCache->begin<components::GlobalRect>();
		auto summationLayerIt = summationCache->begin<components::Layer>();
		for (middle::Id id : summationCache->relevantIdVector) {
			// render functionlabel
			auto transform = *summationTransformIt;
			auto rect = *summationRectIt;
			auto layer = *summationLayerIt;
			size_t index = renderBubble(gameState, middle::RenderObjectType::SUMMATION_RECT, getLayer(gameState, layer), transform, rect);
		}

	}

};

static middle::SystemRegistrar<BubbleRenderSetup> reg("BubbleRenderSetup");
