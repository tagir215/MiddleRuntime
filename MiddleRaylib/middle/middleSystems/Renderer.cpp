#pragma once
#include "raylib.h"
#include "middle_system_registrar.h"
#include "rlImGui.h"
#include "imgui.h"
#include <cstdlib>
#include <thread>
#include "middle_math.h"
#include "middle_state.h"
#include "middle_math_maping_helper.h"
#include "MiddleImGuiTranslatorSystem.cpp"
#include "BubbleRenderer.cpp"

const int fontUnitFactor = 1024;

namespace renderer {


	static void draw3D(const middle::MiddleOutputState* const middleState, middle::MiddleInputState& inputState, bool disabledDepthTest, const Camera& const camera, const std::vector<Shader>& shaders, const std::vector<Texture>& textures, int layerPass = 0) {

		const Vector3 middleForward = toRVec(midMath::MIDDLE_FORWARD_VECTOR);

		rlSetClipPlanes(inputState.nearPlaneDistance, inputState.farPlaneDistance);

		auto& data = middleState->newRenderData;
		for (size_t i : data.activeIndexes) {
			switch (data.types[i]) {
			case middle::RenderObjectType::MIDDLE_MAN:
				Transform transform = toRTransform(data, i);
				pushMatrix(transform);
				const float radius = 3;
				DrawSphereEx({0,0,0}, radius, 5, 5, ORANGE);
				rlPopMatrix();
			}
		}

		EndMode3D();
	}

	static void drawText(const middle::MiddleOutputState* const middleState, bool uiText, const Font& font, const Camera& camera) {
		auto& data = middleState->newRenderData;
		for (size_t i : data.activeIndexes) {

			if (data.types[i] == middle::RenderObjectType::EDITOR_TEXT) {
				const int spacing = 0;
				const float editorFontSize = 10;
				Transform transform = toRTransform(data, i);
				float yDistance = std::abs(middleState->activeCamera.position.y - transform.translation.y);
				float distFactor = 1 / yDistance;
				float fontFactor = fontUnitFactor * distFactor;
				float scaledFontSize = editorFontSize * transform.scale.x * fontFactor;

				const char* text = data.texts[i];
				Vector2 rect = MeasureTextEx(font, text, scaledFontSize, spacing);
				Vector2 offset = { -rect.x * 0.5f, -rect.y * 0.5f };
				Vector2 pos = GetWorldToScreen(transform.translation, camera);

				DrawTextEx(font, text, pos + offset, scaledFontSize, spacing, BLACK);
			}

		}
	}

	class RendererSystem {
	public:
		static void update(
			const middle::MiddleOutputState* const middleState, 
			middle::MiddleInputState& inputState, 
			const Font& font, 
			const std::vector<Shader>& shaders, 
			const std::vector<Texture>& textures, 
			bool releaseBuild) {

			BeginDrawing();

			if (middleState->applicationMode == middle::ApplicationMode::EDITOR_MODE) {
				// 89, 135, 168
				ClearBackground(toRColor(middleState->backgroundColor));

				Camera camera = toRCam(middleState->activeCamera);

				BeginMode3D(camera);
				draw3D(middleState, inputState, false, camera, shaders, textures);
				EndMode3D();

				SetTextLineSpacing(0);

				drawText(middleState, true, font, camera);
			}
			else {
				middle::BubbleRenderer::update(inputState, middleState, font, shaders, textures);
			}

			// draw imgui
			if (!releaseBuild) {
				rlImGuiBegin();
				MiddleImGuiTranslatorSystem::Update(middleState, inputState);
				rlImGuiEnd();
			}

			EndDrawing();
		}
	};

}
