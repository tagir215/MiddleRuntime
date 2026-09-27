#include "abstract_ui.h"

namespace middleUI {

	size_t UiBuilder::newImGuiCall(UiCallType type, size_t id)
	{
		UiCall call;
		call.type = type;
		call.id = id;
		outputState->uiCalls.push_back(call);
		++*iterIndex;
		return id;
	}

	void UiBuilder::label(const char* label)
	{
		outputState->uiCalls.back().label = label;
	}

	void UiBuilder::boolean(bool value)
	{
		outputState->uiCalls.back().boolVal = value;
	}

	void UiBuilder::integer(int value)
	{
		outputState->uiCalls.back().intVal = value;
	}

	void UiBuilder::floating(float value)
	{
		outputState->uiCalls.back().floatVal = value;
	}

	void UiBuilder::string(const char* value)
	{
		outputState->uiCalls.back().stringVal = value;
	}
	void UiBuilder::items(const char* const* value)
	{
		outputState->uiCalls.back().items = value;
	}


	void UiBuilder::minMax(int min, int max) {
		outputState->uiCalls.back().min = min;
		outputState->uiCalls.back().max = max;
	}
	void UiBuilder::active(bool active) {
		outputState->uiCalls.back().active = active;
	}

	void UiBuilder::setSize(size_t size)
	{
		outputState->uiCalls.back().size = size;
	}

	size_t UiBuilder::getId()
	{
		return outputState->uiCalls.back().id;
	}

	UiCall* UiBuilder::getResult(size_t id)
	{
		int index = *iterIndex;
		if (inputState->resultUiCalls.size() <= index) {
			return nullptr;
		}
		// SAFETY CHECK
		// checking that we are really dealing with the same ui item
		// ui calls are usually deterministic when ui is stable, however 
		// when ui changes the callbacks can still point to old ui items/widgets/things
		if (inputState->resultUiCalls[index].id != id) {
			return nullptr;
		}
		return &inputState->resultUiCalls[index];
	}

	void UiBuilder::syncUiCalls()
	{
		outputState->uiCalls.back() = inputState->resultUiCalls[*iterIndex];
	}

}
