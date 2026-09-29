#include <raylib.h>
#include "middle_state.h"
#include "rlImGui.h"
#include "rlgl.h"

namespace middle{


	class BubbleRenderer {
	public:
		static void Update(
			middle::MiddleInputState& inputState,
			const middle::MiddleOutputState* const outputState,
			const std::vector<Texture>& textures,
			const std::vector<Shader>& shaders
		)
		{

			//BeginDrawing();

			//// 89, 135, 168
			//ClearBackground(WHITE);

			//Camera camera = toRCam(middleState->activeCamera);

			//BeginMode3D(camera);

			//auto& data = outputState->newRenderData;
			//for (int i = 0; i < data.size; ++i) {
			//	auto type = data.types[i];
			//	switch (type) {
			//	case(middle::ADDITION_RECT):

			//		//rlPushMatrix();
			//		//rlLoadIdentity();
			//		//rlMultMatrixf(MatrixToFloatV(M).v);
			//		//Vector3 pos = toRVec(item.center);
			//		//if (item.texture == middleAssets::TEXTURE::TEXTURE_NONE) {
			//		//	DrawCube(pos, 4, 4, 4, BLACK);
			//		//}
			//		//else {
			//		//	if (item.shader != middleAssets::SHADER::SHADER_NONE)
			//		//		BeginShaderMode(shaders[item.shader]);

			//		//	DrawBillboard(camera, textures[item.texture], pos, item.textureScale, toRColor(item.color));

			//		//	if (item.shader != middleAssets::SHADER::SHADER_NONE)
			//		//		EndShaderMode();
			//		//}
			//		//rlPopMatrix();

			//		break;
			//	}

			//}

			//EndMode3D();
		}
	};
}
