#include "EditorConfigs.h"

namespace components {
	static void serialize(middle::MiddleMan& shape, std::ostream& ostream) {
		middle::Serializer serializer{ ostream };
		reflectEditorConfigs(shape, serializer);
	}
	static void deserialize(middle::MiddleMan& shape, const std::vector<std::string>& buffer, int indexOffset) {
		middle::Deserializer deserializer{ buffer, indexOffset, 0 };
		reflectEditorConfigs(shape, deserializer);
	}
	static void getFields(middle::MiddleMan& shape, std::vector<middle::FieldInfo>& fields, int* size)
	{
		middle::FieldCollector collector{ fields, size };
		reflectEditorConfigs(shape, collector);
	}
	static middle::ComponentReflectionMethods refMethods = 
	{
		&serialize,
		&deserialize,
		&getFields
	};
	static middle::ComponentRegistrar<EditorConfigs>reg("EditorConfigs", refMethods);
}