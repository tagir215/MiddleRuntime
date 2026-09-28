#include "BubblePathMark.h"

namespace components {
	static void serialize(middle::Shape& shape, std::ostream& ostream) {
		middle::Serializer serializer{ ostream };
		reflectBubblePathMark(shape, serializer);
	}
	static void deserialize(middle::Shape& shape, const std::vector<std::string>& buffer, int indexOffset) {
		middle::Deserializer deserializer{ buffer, indexOffset, 0 };
		reflectBubblePathMark(shape, deserializer);
	}
	static void getFields(middle::Shape& shape, std::vector<middle::FieldInfo>& fields, int* size)
	{
		middle::FieldCollector collector{ fields, size };
		reflectBubblePathMark(shape, collector);
	}
	static middle::ComponentReflectionMethods refMethods = 
	{
		&serialize,
		&deserialize,
		&getFields
	};
	static middle::ComponentRegistrar<BubblePathMark>reg("BubblePathMark", refMethods);
}