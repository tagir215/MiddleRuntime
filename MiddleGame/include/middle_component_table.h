#pragma once 
#include <vector>
#include <unordered_map>
#include <memory>
#include <functional>
#include <cassert>
#include "middle_serialize.h"
#include <any>


namespace middle {
	struct Component;

	struct ComponentReflectionMethods {
		void(*serialize)(middle::Shape&, std::ostream&);
		void(*deserialize)(middle::Shape&, const std::vector<std::string>&, int);
		void(*getFields)(middle::Shape&, std::vector<middle::FieldInfo>&, int*);
	};

	struct IComponentVectorContainer {
		virtual ~IComponentVectorContainer() = default;
		virtual int grow() = 0;
		virtual void shrink(int componentOffset) = 0;
	};
	template<typename T> 
	struct ComponentVectorContainer : public IComponentVectorContainer {
		std::vector<T> vectorData;
		std::vector<int>freeList = {};
		int grow() override {
			if (freeList.size() > 0) {
				int nextFreeIndex = freeList.back();
				freeList.pop_back();
				return nextFreeIndex;
			}

			int nextFreeIndex = vectorData.size();
			vectorData.resize(nextFreeIndex+1);
			return nextFreeIndex;
		}

		void shrink(int componentOffset) {
			freeList.push_back(componentOffset);
			vectorData[componentOffset] = T();
		}
	};

	inline int globalTypeCounter = 0;
	template<typename T>
	inline int getTypeId() {
		static int id = globalTypeCounter++;
		return id;
	}

	extern std::unordered_map <std::string, int> componentTypeMap;
	extern std::unordered_map <int, std::string> componentNameMap;
	extern std::unordered_map <int, std::unique_ptr<IComponentVectorContainer>> componentListMap;
	extern std::vector<ComponentReflectionMethods>reflectionMethodVector;


	template<typename T>
	inline ComponentVectorContainer<T>* getComponentVectorContainer() {
		int typeId = getTypeId<T>();
		IComponentVectorContainer* iContainer = componentListMap[typeId].get();
		ComponentVectorContainer<T>* vectorContainer = static_cast<ComponentVectorContainer<T>*>(iContainer);
		return vectorContainer;
	}

	template<typename T>
	inline void registerToComponentTypes(const std::string& componentName, const ComponentReflectionMethods& reflectionMethods) {
		int typeId = getTypeId<T>();
		componentTypeMap[componentName] = typeId;
		componentNameMap[typeId] = componentName;
		// vector container
		auto vectorContainer = std::make_unique<ComponentVectorContainer<T>>();
		vectorContainer->vectorData = std::vector<T>();
		componentListMap[typeId] = std::move(vectorContainer);
		reflectionMethodVector.push_back(reflectionMethods);
	}

	template<typename T>
	inline T* getComponent(Shape& shape) {
		int typeId = getTypeId<T>();
		int offset = shape.componentOffsets[typeId];
		if (offset == middle::UNASSIGNED) {
			return nullptr;
		}
		ComponentVectorContainer<T>* vectorContainer = getComponentVectorContainer<T>();
		T& t = vectorContainer->vectorData[offset];
		return &t;
	}


	template<typename T>
	inline T* addComponent(Shape& shape) {
		int typeId = getTypeId<T>();
		ComponentVectorContainer<T>* vectorContainer = getComponentVectorContainer<T>();
		auto& data = vectorContainer->vectorData;
		int nextIndex = vectorContainer->grow();
		T t;
		data[nextIndex] = t;
		setCompOffset(shape, typeId, nextIndex);
		return &data[nextIndex];
	}

	template<typename T>
	inline void deleteComponent(Shape& shape) {
		int typeId = getTypeId<T>();
		ComponentVectorContainer<T>* vectorContainer = getComponentVectorContainer<T>();
		int offset = getCompOffset(shape, typeId);
		vectorContainer->shrink(offset);
		removeComp(shape, typeId);
	}

	inline ComponentReflectionMethods& getComponentReflectionMethods(int typeId) {
		return reflectionMethodVector[typeId];
	}
}