#include "middle_state.h"
#include "imgui.h"


class MiddleImGuiTranslatorSystem {
public:

	static void translateCall(const middleUI::UiCall& call) {
		switch (call.type) {
		case(middleUI::Begin):
			ImGui::Begin(call.label);
			break;
		case(middleUI::End):
			ImGui::End();
			break;
		case(middleUI::Text):
			ImGui::Text(call.stringVal);
			break;
		case(middleUI::Button):
			*call.boolVal = ImGui::Button(call.label);
			break;
		case(middleUI::Checkbox):
			ImGui::Checkbox(call.label, call.boolVal);
			break;
			// TODOOOOOOOOOOOOOOOOOOOOOOOOOO
		case(middleUI::Combo):
			break;
		case(middleUI::BeginPopup):
			*call.boolVal = ImGui::BeginPopup(call.label);
			break;
		case(middleUI::EndPopup):
			ImGui::EndPopup();
			break;
		case(middleUI::OpenPopup):
			ImGui::OpenPopup(call.label);
			break;
		case(middleUI::CloseCurrentPopup):
			ImGui::CloseCurrentPopup();
			break;
		case(middleUI::CollapsingHeader):
			ImGui::CollapsingHeader(call.label);
			break;
		case(middleUI::InputText):
			ImGui::InputText(call.label, call.stringVal, call.size);
			break;
		}
	}


	static void Update(const middle::MiddleOutputState* const middleState) {
		for (const auto& call : middleState->uiCalls) {
			translateCall(call);
		}
	}
};
