#include <raylib.h>
#include "middle_state.h"
#include "rlImGui.h"
#include "rlgl.h"
#include "middle_math_maping_helper.h"

namespace bubbleColors {
	Color BACKGROUND = WHITE;
	Color BUBBLE = { 190,190,190,255 };
	Color LOGIC = { 220,220,220,255 };
	Color CLOSED_GATE = { 220,30,30,255 };
	Color OPEN_GATE = { 30,200,30,255 };
	Color DUMMY_GATE = {100,100,100,255};
	Color POSITIVE_UNIT = WHITE;
	Color NEGATIVE_UNIT = BLACK;
	Color UNIT_TEXT_POSITIVE = BLACK;
	Color UNIT_TEXT_NEGATIVE = WHITE;
	Color MULTIPLICATION = {58,81,66,255};
	Color MULTIPLICATION_TEXT = BLACK;
	Color POWER = {165,117,163,255};
	Color POWER_TEXT = BLACK;
	Color EQUALS = {171,151,223,255};
	Color EQUALS_TEXT = BLACK;
	Color INEQUALS = {65,32,32,255};
	Color INEQUALS_TEXT = BLACK;
	Color SUMMATION = {246,145,122,244};
	Color SUMMATION_TEXT = BLACK;
	Color FUNCTION = {142,153,227,255};
	Color FUNCTION_TEXT = BLACK;
}

namespace middle{

	Color calculateFadedColor(const Color& color, const Transform& transform, const Camera& camera, int layer, float nearPlaneAxisY, float nearPlaneDistance, float bubbleAxis) {
		const Color background = bubbleColors::BACKGROUND;

		const float oneChildScaleRatio = 0.758;
		const float stepScale = 1.0f / oneChildScaleRatio;
		float layerOffset = 0;

		float camDist = camera.position.y;
		// todo... is cosntant
		float axisY = nearPlaneAxisY / nearPlaneDistance * -camDist;

		const float firstStepScale = axisY / bubbleAxis;

		float maxScale = firstStepScale * 0.5f;
		float minScale = 0.0001f;

		float scaleRatio = transform.scale.x / maxScale;
		if (scaleRatio > 1) {
			scaleRatio = 1;
		}

		float s = scaleRatio;

		s = std::powf(s, 0.20f);

		Color result;
		result.r = color.r * s + background.r * (1 - s);
		result.g = color.g * s + background.g * (1 - s);
		result.b = color.b * s + background.b * (1 - s);
		result.a = 255;

		return result;
	}


	const void rotateTexture(Transform& transform) {
		// rotate 45 degrees in middle forward axissh
		const Vector3 middleForward = toRVec(midMath::MIDDLE_FORWARD_VECTOR);
		const Vector3 MiddleForwardRotated = { 0,0,1 };
		Quaternion rotation = QuaternionFromVector3ToVector3(middleForward, MiddleForwardRotated);
		transform.rotation = rotation;
		pushMatrix(transform);
	}

	void renderBubble(const middle::RenderData& data, int index, const Color& color, const Shader& shader, const Camera& camera, const Texture& texture) {
		Transform transform = toRTransform(data, index);
		rotateTexture(transform);
		pushMatrix(transform);
		BeginShaderMode(shader);
		// ??
		const float textureScale = 10;
		DrawBillboard(camera, texture, { 0,0,0 }, textureScale, WHITE);
		EndShaderMode();
		rlPopMatrix();
	}

	class BubbleRenderer {
	public:
		static void update(
			middle::MiddleInputState& inputState,
			const middle::MiddleOutputState* const outputState,
			const Font& font,
			const std::vector<Shader>& shaders,
			const std::vector<Texture>& textures
		)
		{

			BeginDrawing();

			// 89, 135, 168
			ClearBackground(WHITE);

			Camera camera = toRCam(outputState->activeCamera);

			BeginMode3D(camera);

			auto& data = outputState->newRenderData;
			for (size_t i : data.activeIndexes) {
				auto type = data.types[i];
				switch (type) {
				case(middle::ADDITION_RECT):
					renderBubble(data, i, WHITE, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::MULTIPLICATION_RECT):
					renderBubble(data, i, bubbleColors::MULTIPLICATION, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::POWER_RECT):
					renderBubble(data, i, bubbleColors::POWER, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::SUMMATION_RECT):
					renderBubble(data, i, bubbleColors::SUMMATION, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::FUNCTION_RECT):
					renderBubble(data, i, bubbleColors::FUNCTION, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::EQUALS_RECT):
					renderBubble(data, i, bubbleColors::EQUALS, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::GREATER_RECT):
					renderBubble(data, i, bubbleColors::INEQUALS, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::TEXT_RECT):
					renderBubble(data, i, WHITE, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::GREATER_OR_EQUALS_RECT):
					renderBubble(data, i, bubbleColors::INEQUALS, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::AND_LOGIC_GATE_RECT):
					renderBubble(data, i, bubbleColors::LOGIC, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				case(middle::GATE_RECT):
					Color color = data.states[i] == middle::RenderObjectState::GATE_CLOSED ?
						bubbleColors::CLOSED_GATE : bubbleColors::OPEN_GATE;
					renderBubble(data, i, color, shaders[middleAssets::SHADER::BUBBLE_SHADER], camera, textures[middleAssets::TEXTURE::BACKGROUND]);
					break;
				default:
					assert(false);
				}
			}

			EndMode3D();
		}
	};
}
