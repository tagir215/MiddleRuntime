#pragma once
#include "middle_shape_utils.h"
#include "middle_state.h"

namespace middleUI {
#define MID_ARRAYSIZE(_ARR)          ((int)(sizeof(_ARR) / sizeof(*(_ARR))))

	// A simple bit-combining function used by boost
	inline void hash_combine(std::size_t& seed, std::size_t value) {
		seed ^= value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
	}

	inline std::size_t generate_runtime_id(std::string_view file, int line, int i) {
		std::size_t seed = std::hash<std::string_view>{}(file);
		hash_combine(seed, std::hash<int>{}(line));
		hash_combine(seed, std::hash<int>{}(i));
		return seed;
	}


	struct UiBuilder {
		middle::MiddleOutputState* outputState = nullptr;
		middle::MiddleInputState* inputState = nullptr;
		int* iterIndex;

		UiBuilder(middle::GameState* gameState) {
			this->inputState = &gameState->middleInputState;
			this->outputState = &gameState->middleState;
			this->iterIndex = &gameState->resultUiCallIterIndex;
		}


		size_t newImGuiCall(UiCallType type, size_t index);
		void label(const char* label);
		void boolean(bool value);
		void integer(int value);
		void floating(float value);
		void string(const char* value);
		void items(const char* const* value);
		void minMax(int min, int max);
		void active(bool active);
		void setSize(size_t size);
		size_t getId();
		UiCall* getResult(size_t id);
		// since this ui works in strange ways,
		// imagine value changes after clicking a checkbox
		// now you get result at frame delay, but youre already
		// updating the next call at this point.. anyway to avoid
		// back and forth state changes, when value changes call this
		void syncUiCalls();

	};

#define midgui(type) \
		newImGuiCall(type, generate_runtime_id(__FILE__,__LINE__,0))
#define midgui_index(type, index) \
		newImGuiCall(type, generate_runtime_id(__FILE__,__LINE__,index))

#define START_MIDGUI(gameState) \
		auto builder = UiBuilder(gameState)


#define midguiSync builder.syncUiCalls()

	static inline void _midguiBegin(const char* label, UiBuilder& builder) {
		builder.midgui(Begin);
		builder.label(label);
	}
#define midguiBegin(lbl) _midguiBegin(lbl, builder)


	static inline void _midguiEnd(UiBuilder& builder) {
		builder.midgui(End);
	}
#define midguiEnd() _midguiEnd(builder);


	static inline bool _midguiButton(const char* label, UiBuilder& builder) {
		builder.midgui(Button);
		auto result = builder.getResult(builder.getId());
		builder.label(label);
		return result != nullptr && result->boolVal;
	}
#define midguiButton(lbl) _midguiButton(lbl, builder)


	static inline void _midguiText(const char* text, UiBuilder& builder) {
		builder.midgui(Text);
		builder.string(text);
	}
#define midguiText(text) _midguiText(text, builder)


	static inline bool _midguiIsItemFocused(UiBuilder& builder) {
		size_t id = builder.midgui(IsItemFocused);
		auto result = builder.getResult(id);
		return result != nullptr && result->boolVal;
	}
#define midguiIsItemFocused() _midguiIsItemFocused(builder)


	static inline bool _midguiIsAnyItemFocused(UiBuilder& builder) {
		size_t id = builder.midgui(IsAnyItemFocused);
		auto result = builder.getResult(id);
		return result != nullptr && result->boolVal;
	}
#define midguiIsAnyItemFocused() _midguiIsAnyItemFocused(builder)


	static inline bool _midguiSliderInt(
		const char* label,
		int& currentValue,
		int min,
		int max,
		UiBuilder& builder
	) {
		size_t id = builder.midgui(SliderInt);
		auto result = builder.getResult(id);
		if (result != nullptr) {
			currentValue = result->intVal;
		}
		builder.label(label);
		builder.integer(currentValue);
		builder.minMax(min, max);

		return result != nullptr && result->boolVal;
	}
#define midguiSliderInt(lbl, value, min, max) \
    _midguiSliderInt(lbl, value, min, max, builder)


	static inline void _midguiSeparator(UiBuilder& builder) {
		builder.midgui(Separator);
	}
#define midguiSeparator() _midguiSeparator(builder)


	static inline bool _midguiCheckbox(
		const char* label,
		bool& currentValue,
		UiBuilder& builder
	) {
		size_t id = builder.midgui(Checkbox);
		auto result = builder.getResult(id);
		if (result != nullptr) {
			currentValue = result->boolVal;
		}
		builder.label(label);
		builder.boolean(currentValue);

		return result != nullptr && result->boolVal;
	}
#define midguiCheckbox(lbl, value) _midguiCheckbox(lbl, value, builder)


	static inline void _midguiSameLine(UiBuilder& builder) {
		builder.midgui(SameLine);
	}
#define midguiSameLine() _midguiSameLine(builder)


	static inline bool _midguiRadioButton(
		const char* label,
		bool active,
		UiBuilder& builder
	) {
		size_t id = builder.midgui(RadioButton);
		auto result = builder.getResult(id);
		builder.label(label);
		builder.active(active);

		return result != nullptr && result->boolVal;
	}
#define midguiRadioButton(lbl, active) \
    _midguiRadioButton(lbl, active, builder)


	static inline bool _midguiIsWindowHovered(UiBuilder& builder) {
		size_t id = builder.midgui(IsWindowHovered);
		auto result = builder.getResult(id);
		return result != nullptr && result->boolVal;
	}
#define midguiIsWindowHovered() _midguiIsWindowHovered(builder)

	static inline void _midguiCombo(const char* label, const char* const* items, int& currentIndex, int size, UiBuilder& builder) {
		size_t id = builder.midgui(Combo);
		auto result = builder.getResult(id);
		if (result != nullptr) {
			currentIndex = result->intVal;
		}
		builder.label(label);
		builder.items(items);
		builder.setSize(size);
		builder.integer(currentIndex);
	}
#define midguiCombo(lbl, items, currentIndex, size) _midguiCombo(lbl, items, currentIndex, size, builder)

	static inline void _midguiBeginPopup(
		const char* label,
		UiBuilder& builder
	) {
		builder.midgui(BeginPopup);
		builder.label(label);
	}
#define midguiBeginPopup(lbl) _midguiBeginPopup(lbl, builder)


	static inline void _midguiEndPopup(UiBuilder& builder) {
		builder.midgui(EndPopup);
	}
#define midguiEndPopup() _midguiEndPopup(builder)


	static inline void _midguiOpenPopup(
		const char* label,
		UiBuilder& builder
	) {
		builder.midgui(OpenPopup);
		builder.label(label);
	}
#define midguiOpenPopup(lbl) _midguiOpenPopup(lbl, builder)


	static inline void _midguiCloseCurrentPopup(UiBuilder& builder) {
		builder.midgui(CloseCurrentPopup);
	}
#define midguiCloseCurrentPopup() _midguiCloseCurrentPopup(builder)


	static inline void _midguiCollapsingHeader(
		const char* label,
		UiBuilder& builder
	) {
		builder.midgui(CollapsingHeader);
		builder.label(label);
	}
#define midguiCollapsingHeader(lbl) \
    _midguiCollapsingHeader(lbl, builder)


	static inline bool _midguiIsItemClickedMouseLeft(UiBuilder& builder) {
		auto id = builder.midgui(IsItemClickedMouseLeft);
		auto result = builder.getResult(id);
		return result != nullptr && result->boolVal;
	}
#define midguiIsItemClickedMouseLeft() \
    _midguiIsItemClickedMouseLeft(builder)
}
