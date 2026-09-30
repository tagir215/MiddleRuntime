#include "middle_state.h"
#include "imgui.h"


class MiddleImGuiTranslatorSystem {
public:

	static void translateCall(int i, const middle::MiddleOutputState* const middleState, middle::MiddleInputState& inputState) {
		auto copyCall = middleState->uiCalls[i];
		switch (copyCall.type) {
		case(middleUI::Begin):
			ImGui::Begin(copyCall.label);
			break;
		case(middleUI::End):
			ImGui::End();
			break;
		case(middleUI::Text):
			ImGui::Text(copyCall.stringVal);
			break;
		case(middleUI::Button):
			copyCall.boolVal = ImGui::Button(copyCall.label);
			break;
		case(middleUI::Checkbox):
			ImGui::Checkbox(copyCall.label, &copyCall.boolVal);
			break;
		case(middleUI::Combo):
			ImGui::Combo(copyCall.label, &copyCall.intVal, copyCall.items, copyCall.size);
			break;
		case(middleUI::BeginPopup):
			copyCall.boolVal = ImGui::BeginPopup(copyCall.label);
			break;
		case(middleUI::EndPopup):
			ImGui::EndPopup();
			break;
		case(middleUI::OpenPopup):
			ImGui::OpenPopup(copyCall.label);
			break;
		case(middleUI::CloseCurrentPopup):
			ImGui::CloseCurrentPopup();
			break;
		case(middleUI::CollapsingHeader):
			ImGui::CollapsingHeader(copyCall.label);
			break;
		case(middleUI::RadioButton):
			copyCall.boolVal = ImGui::RadioButton(copyCall.label, copyCall.active);
			break;
		case(middleUI::InputText):
			// TOOOOOOOOOOOOOOOOOOOOOOOOOOOOODDDDDDDDDOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
			//ImGui::InputText(copyCall.label, copyCall.stringVal, copyCall.size);
			break;
		case(middleUI::SameLine):
			ImGui::SameLine();
			break;
		case(middleUI::Separator):
			ImGui::Separator();
			break;
		case(middleUI::SliderInt):
			ImGui::SliderInt(copyCall.label, &copyCall.intVal, copyCall.min, copyCall.max);
			break;
		}

		inputState.resultUiCalls.push_back(copyCall);
	}


	static void Update(const middle::MiddleOutputState* const middleState, middle::MiddleInputState& inputState) {
		inputState.resultUiCalls.clear();
		for (int i = 0; i < middleState->uiCalls.size(); ++i) {
			translateCall(i, middleState, inputState);
		}
	}
};
