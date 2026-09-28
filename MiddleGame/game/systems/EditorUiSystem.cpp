#pragma once
#include "game_state.h"
#include "editor_actions.h"
#include "middle_system_registrar.h"
#include "middle_shape_utils.h"
#include "MidComp/LoopSociety.h"
#include "MidComp/EditorConfigs.h"
#include "abstract_ui.h"

class EditorUiSystem : public middle::MiddleGameplaySystem {
public:
	EditorUiSystem() {
		systemUpdateType = middle::SystemUpdateType::POSTFRAME;
		systemModeType = middle::SystemModeType::ENGINE;
	}

	void init(middle::GameState* gameState) {

	}

	void editorUi(middle::GameState* gameState) {

		middle::Id& editorConfigs = 
			middle::findFirstShapeWithComp(gameState, middle::getTypeId<components::EditorConfigs>());

		components::EditorConfigs* configs = nullptr;
		if (editorConfigs.index != middle::UNASSIGNED) {
			auto& configShape = middle::getShape(gameState, editorConfigs.index);
			configs = middle::getComponent<components::EditorConfigs>(configShape);
		}


		using namespace middleUI;
		static bool isWindowHovered = false;

		START_MIDGUI(gameState);
		midguiBegin("Control");
		if (midguiButton("undo")) {
			if (gameState->editorState.actionHistory.size() > 0) {
				int lastIndex = gameState->editorState.actionHistory.size() - 1;
				int targetIndex = lastIndex - gameState->editorState.historySinkDepth;
				auto actionToUndo = gameState->editorState.actionHistory[targetIndex];
				gameState->undoQueue.push(actionToUndo);
				++gameState->editorState.historySinkDepth;
			}
		}
		if (midguiButton("redo")) {
			if (gameState->editorState.historySinkDepth > 0) {
				int lastIndex = gameState->editorState.actionHistory.size() - 1;
				--gameState->editorState.historySinkDepth;
				int targetIndex = lastIndex - gameState->editorState.historySinkDepth;
				auto actionToRedo = gameState->editorState.actionHistory[targetIndex];
				gameState->actionQueue.push(actionToRedo);
			}
		}
		if (midguiButton("reset")) {
			gameState->reset = true;
		}
		if (midguiButton("play")) {
			gameState->middleState.applicationMode = middle::ApplicationMode::GAME_MODE;
		}
		midguiEnd();



		midguiBegin("Editor");

		static const char* items[] = {"SELECT MODE", "SPHERE MODE", "CONSTRAINT MODE", "CAMERA MODE", "LOOP_MODE"};
		int currentItem = static_cast<int>(gameState->editorState.creationMode);
		int itemsSize = MID_ARRAYSIZE(items);
		midguiCombo("Select things to add", items, currentItem, itemsSize);
		gameState->editorState.creationMode = static_cast<middle::CreationMode>(currentItem);


		midguiEnd();

		//	// SCENE MANAGER

		//midguiSeparator();

		//if (gameState->sceneNames.size() > 0) {
		//	midguiText(("ActiveScene: " + gameState->activeSceneName).c_str());
		//}

		//static int action = 0;
		//int load = 1;
		//int import = 2;
		//// Add new scene button
		//if (midguiButton("OPEN SCENE")) {
		//	midguiOpenPopup("Scene Selector");
		//	action = load;
		//}


		//if (midguiButton("IMPORT SCENE")) {
		//	midguiOpenPopup("Scene Selector");
		//	action = import;
		//}

		//if (midguiBeginPopup("Scene Selector")) {

		//	for (int i = 0; i < gameState->sceneNames.size(); ++i) {
		//		auto name = gameState->sceneNames[i];
		//		if (midguiButton(name.c_str())) {
		//			if (action == load) {
		//				middle::queueAction(gameState, std::make_shared<middle::EditorActionLoadScene>(name));
		//			}
		//			if (action == import) {
		//				middle::queueEditorAction(gameState, std::make_shared<middle::EditorActionImportScene>("../assets/scenes/", name));
		//			}

		//			midguiCloseCurrentPopup();
		//		}
		//	}

		//	midguiEndPopup();
		//}

		//if (midguiButton("IMPORT SHAPE")) {
		//	midguiOpenPopup("Shape Selector");
		//}

		//if (midguiBeginPopup("Shape Selector")) {
		//	for (int i = 0; i < gameState->shapeNames.size(); ++i) {
		//		auto name = gameState->shapeNames[i];
		//		if (midguiButton(name.c_str())) {
		//			middle::queueEditorAction(gameState, std::make_shared<middle::EditorActionImportScene>("../assets/shapes/", name));
		//			midguiCloseCurrentPopup();
		//		}
		//	}
		//	midguiEndPopup();
		//}

		// Add new scene button
		//if (midguiButton("ADD NEW SCENE")) {
		//	midguiOpenPopup("New Scene Popup");
		//}

		//// Popup for entering new scene name
		//static char newSceneName[128] = ""; // buffer for scene name input
		//if (midguiBeginPopup("New Scene Popup")) {
		//	middle::insertInputBlock(gameState, middle::InputBlockers::KEYBOARD_BLOCK);

		//	midguiText("Enter new scene name:");
		//	ImGui::InputText("##newSceneName", newSceneName, IM_ARRAYSIZE(newSceneName));

		//	if (ImGui::Button("Add")) {
		//		if (strlen(newSceneName) > 0) {
		//			// Add the new scene to the editor
		//			middle::queueAction(gameState, std::make_shared<middle::EditorActionNewScene>(newSceneName));

		//			// Clear buffer and close popup
		//			newSceneName[0] = '\0';
		//			ImGui::CloseCurrentPopup();
		//		}
		//	}
		//	ImGui::SameLine();
		//	if (ImGui::Button("Cancel")) {
		//		newSceneName[0] = '\0';
		//		ImGui::CloseCurrentPopup();
		//	}

		//	ImGui::EndPopup();
		//}

		//if (ImGui::Button("Sync Generations")) {
		//	middle::loopInstances(gameState, [gameState](int j, middle::Shape& shape) {
		//		auto loop = middle::getComponent<components::LoopSociety>(shape);
		//		if (loop) {
		//			for (int index = 0; index < loop->loopMemberIds.size(); ++index) {
		//				loop->loopMemberIds[index] = gameState->ids[loop->loopMemberIds[index].index];
		//			}
		//			if (loop->parentLoopId.index != middle::UNASSIGNED) {
		//				loop->parentLoopId = gameState->ids[loop->parentLoopId.index];
		//			}
		//		}
		//		return true;
		//		});
		//}


		//ImGui::Separator();

		//ImGui::End();





		//	// SCRIPT MANAGER

		//	ImGui::Begin("System Manager");

		//	// import SCRIPT
		//	if (ImGui::Button("IMPORT SYSTEM")) {
		//		ImGui::OpenPopup("System Selector");
		//	}

		//	// import COMPONENT
		//	ImGui::Button("IMPORT COMPONENT");
		//	if (ImGui::IsItemClicked(ImGuiMouseButton_Left)) {
		//		ImGui::OpenPopup("Component Selector");
		//	}


		//	if (ImGui::BeginPopup("System Selector")) {

		//		for (auto& name : gameState->systemNames) {
		//			if (ImGui::Button(name.c_str())) {

		//				middle::queueEditorAction(gameState, std::make_shared<middle::EditorActionImportSystem>(name));

		//				ImGui::CloseCurrentPopup();
		//			}
		//		}

		//		ImGui::EndPopup();
		//	}


		//	if (ImGui::BeginPopup("Component Selector")) {
		//		middle::insertInputBlock(gameState, middle::InputBlockers::MOUSE_BLOCK);
		//		for (auto& name : gameState->componentNames) {
		//			if (ImGui::Button(name.c_str())) {
		//				middle::queueEditorAction(gameState, std::make_shared<middle::EditorActionImportComponent>(name, middle::getSelectedShapes(gameState)));
		//				ImGui::CloseCurrentPopup();
		//			}
		//		}

		//		ImGui::EndPopup();
		//	}

		//	// Add new system button
		//	if (ImGui::Button("ADD NEW SCRIPT")) {
		//		ImGui::OpenPopup("New Script Popup");
		//	}

		//	// Popup for entering new scene name
		//	static char newScriptName[128] = ""; // buffer for scene name input
		//	if (ImGui::BeginPopup("New Script Popup")) {
		//		middle::insertInputBlock(gameState, middle::InputBlockers::KEYBOARD_BLOCK);

		//		ImGui::Text("Enter new initSystem name:");
		//		ImGui::InputText("##newScriptName", newScriptName, IM_ARRAYSIZE(newScriptName));

		//		const char* systemItems[] = { "SYSTEM", "COMPONENT" };
		//		static int selectedSystemItem = 0;
		//		ImGui::Combo("Component or System?", &selectedSystemItem, systemItems, IM_ARRAYSIZE(systemItems));

		//		if (ImGui::Button("Add")) {
		//			if (strlen(newScriptName) > 0) {
		//				// Add the new scene to the editor
		//				if (selectedSystemItem == 0) {
		//					middle::queueAction(gameState, std::make_shared<middle::EditorActionNewSystem>(newScriptName));
		//				}
		//				else {
		//					middle::queueAction(gameState, std::make_shared<middle::EditorActionNewComponent>(newScriptName));
		//				}

		//				// Clear buffer and close popup
		//				newScriptName[0] = '\0';
		//				ImGui::CloseCurrentPopup();
		//			}
		//		}
		//		ImGui::SameLine();
		//		if (ImGui::Button("Cancel")) {
		//			newScriptName[0] = '\0';
		//			ImGui::CloseCurrentPopup();
		//		}

		//		ImGui::EndPopup();
		//	}

		//	ImGui::End();


		//	ImGui::End();

		//	};

		//middle::queueUi(gameState, oldUI);
	}

	void gameEditorUi(middle::GameState* gameState) {

		//auto ui = [gameState]() {
		//	ImGui::Begin("Control");
		//	if (ImGui::Button("Edit")) {
		//		gameState->applicationMode = middle::ApplicationMode::EDITOR_MODE;
		//	}
		//	ImGui::End();
		//	};

		//middle::queueUi(gameState, ui);
	}

	void update(middle::GameState* gameState) override {


		if (gameState->middleState.applicationMode == middle::ApplicationMode::EDITOR_MODE) {
			editorUi(gameState);
		}
		if (gameState->middleState.applicationMode == middle::ApplicationMode::GAME_MODE) {
			gameEditorUi(gameState);
		}
	}

};

static middle::SystemRegistrar<EditorUiSystem> reg("EditorUiSystem");
