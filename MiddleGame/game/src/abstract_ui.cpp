#include "abstract_ui.h"

namespace middleUI {

	UiCall* UiBuilder::newImGuiCall(UiCallType type, size_t id)
	{
		UiCall call;
		call.type = type;
		call.id = id;
		state->uiCalls.push_back(call);

		if (state->previousUiCalls.size() <= middle::previousUiCallIterIndex) {
			return nullptr;
		}
		auto previousCallId = state->previousUiCalls[middle::previousUiCallIterIndex].id;
		if (previousCallId != id) {
			return nullptr;
		}
		return &state->previousUiCalls[middle::previousUiCallIterIndex++];
	}

	void UiBuilder::label(char* label)
	{
		state->uiCalls.back().label = label;
	}

	void UiBuilder::boolean(bool value)
	{
		state->uiCalls.back().boolVal = value;
	}

	void UiBuilder::integer(int value)
	{
		state->uiCalls.back().intVal = value;
	}

	void UiBuilder::floating(float value)
	{
		state->uiCalls.back().floatVal = value;
	}

	void UiBuilder::string(char* value)
	{
		state->uiCalls.back().stringVal = value;
	}


	void UiBuilder::minMax(int min, int max) {
		state->uiCalls.back().min = min;
		state->uiCalls.back().max = max;
	}
	void UiBuilder::active(bool active) {
		state->uiCalls.back().active = active;
	}

	void UiBuilder::setSize(size_t size)
	{
		state->uiCalls.back().size = size;
	}

}
