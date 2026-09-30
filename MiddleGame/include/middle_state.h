#pragma once
#include <unordered_map>
#include <string>
#include "middle_primitives.h"
#include <functional>
#include "input.h"
#include <set>
#include "asset_enums.h"
#include <array>

namespace middleUI{
	enum UiCallType {
		None,
		Begin,
		End,
		Text,
		Button,
		InputText,
		IsItemFocused,
		IsAnyItemFocused,
		SliderInt,   // use setMinMax 
		Separator,
		Checkbox,
		SameLine,
		RadioButton,  // use setAcive to set it active/inactive
		IsWindowHovered,
		BeginPopup,
		EndPopup,
		OpenPopup,
		CloseCurrentPopup,
		Combo,
		CollapsingHeader,
		IsItemClickedMouseLeft,
	};

	struct UiCall {
		UiCallType type;
		size_t id;
		const char* label = nullptr;
		bool boolVal;
		int intVal;
		float floatVal;
		const char* stringVal = nullptr;
		const char* const* items = nullptr;
		int min, max;
		size_t size;
		bool active;
	};
}

namespace middle {


	enum RenderItemType {
		SPHERE,
		LINE,
		RECTANGLE,
		CIRCLE,
		TEXT,
		MODEL,
		VECTOR,
		CIRCLE_SECTOR,
		CONE,
		RING,
		CYLINDER,
		CUBOID,
		BILLBOARD,
		BACKGROUND,
	};

	struct RenderItem {
		RenderItemType type;
		midPrimitive::Color color;
		midPrimitive::Color backgroundColor = { 0,0,0,0 };
		midMath::Vector3 center = { 0,0,0 };
		midMath::Vector3 scale = { 1,1,1 };
		midMath::Vector3 linePointA;
		midMath::Vector3 linePointB;
		midMath::Vector3 textOffset = { 0,0,0 };
		midPrimitive::Transform transform;
		int slices = 20;
		float radius;
		float ringRadius;
		float startAngle;
		float endAngle;
		int segments;
		float length = 0;
		float width = 0;
		float height = 0;
		float textureScale = 10;
		int fontSize = 10;
		bool disableDepthTest = false;
		std::string text = "";
		middleAssets::MODEL model;
		middleAssets::TEXTURE texture;
		middleAssets::SHADER shader;


		RenderItem() {
			transform.translation = { 0,0,0 };
			transform.rotation = { 0,0,0 };
			transform.scale = { 1,1,1 };
		}
	};

	enum class ApplicationMode {
		EDITOR_MODE,
		GAME_MODE,
	};

	struct MiddleInputState {
		bool closeGame = false;
		bool releaseBuild = false;
		float screenWidth;
		float screenHeight;
		float frameTime;
		float targetFrameTime;
		double nearPlaneDistance = 10;
		double farPlaneDistance = 4000;
		float cameraFOVY = 45;
		EditorInput editorInput;
		GameInput gameInput;
		EqulabInput equlabInput;
		std::vector<middleUI:: UiCall>resultUiCalls;
	};

	enum RenderObjectState {
		NONE,
		LIZARD_WALKING,
		LIZARD_RUNNING,
		LIZARD_IDLE,
		GATE_OPEN,
		GATE_CLOSED,
		GATE_DUMMY,
		POSITIVE,
		NEGATIVE
	};

	// OK render objects and game all objects are in one large enum. why is that a problem? write a 
	// script that helps you with organization,  but this is how its sent to renderer
	enum RenderObjectType {
		// EDITOR OBJECTS
		MIDDLE_MAN,
		EDITOR_TEXT,

		// GAME OBJECTS
		LIZARD,
		OCARINA_OF_TIME,
		ADDITION_RECT,
		MULTIPLICATION_RECT,
		POWER_RECT,
		SUMMATION_RECT,
		FUNCTION_RECT,
		VARIABLE_RECT,
		UNIT_RECT,
		TEXT_RECT,
		GATE_RECT,
		AND_LOGIC_GATE_RECT,
		EQUALS_RECT,
		GREATER_RECT,
		GREATER_OR_EQUALS_RECT,
	};

	inline const size_t MAX_RENDER_ITEMS_COUNT = 10000;
	struct RenderData {
		std::vector<size_t>activeIndexes;
		std::array<RenderObjectType, MAX_RENDER_ITEMS_COUNT>types;
		std::array<RenderObjectState, MAX_RENDER_ITEMS_COUNT>states;
		std::array<const char*, MAX_RENDER_ITEMS_COUNT>texts;

		std::array<float, MAX_RENDER_ITEMS_COUNT>positionsX;
		std::array<float, MAX_RENDER_ITEMS_COUNT>positionsY;
		std::array<float, MAX_RENDER_ITEMS_COUNT>positionsZ;

		std::array<float, MAX_RENDER_ITEMS_COUNT>rotationsX;
		std::array<float, MAX_RENDER_ITEMS_COUNT>rotationsY;
		std::array<float, MAX_RENDER_ITEMS_COUNT>rotationsZ;
		std::array<float, MAX_RENDER_ITEMS_COUNT>rotationsW;

		std::array<float, MAX_RENDER_ITEMS_COUNT>scalesX;
		std::array<float, MAX_RENDER_ITEMS_COUNT>scalesY;
		std::array<float, MAX_RENDER_ITEMS_COUNT>scalesZ;

	};


	struct MiddleOutputState {
		std::vector<middle::RenderItem> renderData;
		RenderData newRenderData;
		std::vector<std::function<void()>>uiSetups;
		std::vector<middleUI:: UiCall>uiCalls;
		midPrimitive::Color backgroundColor = { 188, 144, 181, 255 };
		midPrimitive::Camera activeCamera;
		std::set<InputBlockers> inputBlockers;
		float frameTimeAccumulator = 0;
		bool closeGame;
		ApplicationMode applicationMode;
	};

}
