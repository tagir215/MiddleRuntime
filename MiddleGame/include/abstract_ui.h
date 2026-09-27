#pragma once
#include <imgui.h>
#include "middle_shape_utils.h"
#include "middle_state.h"

namespace middleUI {

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
		middle::MiddleOutputState* state;

		UiBuilder(middle::MiddleOutputState* state) {
			this->state = state;
		}

		UiCall* newImGuiCall(UiCallType type, size_t index);
		void label(char* label);
		void boolean(bool value);
		void integer(int value);
		void floating(float value);
		void string(char* value);
		void minMax(int min, int max);
		void active(bool active);
		void setSize(size_t size);
	};

	#define midgui(type) \
		newImGuiCall(type, generate_runtime_id(__FILE__,__LINE__,0))
	#define midgui_index(type, index) \
		newImGuiCall(type, generate_runtime_id(__FILE__,__LINE__,index))

}
