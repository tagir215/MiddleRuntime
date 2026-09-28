#include "TopDogBubbleTag.h"

namespace components {
	static void serialize(middle::MiddleMan& shape, std::ostream& ostream) {
		middle::Serializer serializer{ ostream };
		reflectTopDogBubbleTag(shape, serializer);
	}
	static void deserialize(middle::MiddleMan& shape, const std::vector<std::string>& buffer, int indexOffset) {
		middle::Deserializer deserializer{ buffer, indexOffset, 0 };
		reflectTopDogBubbleTag(shape, deserializer);
	}
	static void getFields(middle::MiddleMan& shape, std::vector<middle::FieldInfo>& fields, int* size)
	{
		middle::FieldCollector collector{ fields, size };
		reflectTopDogBubbleTag(shape, collector);
	}
	static middle::ComponentReflectionMethods refMethods = 
	{
		&serialize,
		&deserialize,
		&getFields
	};
	static middle::ComponentRegistrar<TopDogBubbleTag>reg("TopDogBubbleTag", refMethods);
}