#include "EcsPerformanceTestConfigs.h"

namespace components {
	static void serialize(middle::Shape& shape, std::ostream& ostream) {
		middle::Serializer serializer{ ostream };
		reflectEcsPerformanceTestConfigs(shape, serializer);
	}
	static void deserialize(middle::Shape& shape, const std::vector<std::string>& buffer, int indexOffset) {
		middle::Deserializer deserializer{ buffer, indexOffset, 0 };
		reflectEcsPerformanceTestConfigs(shape, deserializer);
	}
	static void getFields(middle::Shape& shape, std::vector<middle::FieldInfo>& fields, int* size)
	{
		middle::FieldCollector collector{ fields, size };
		reflectEcsPerformanceTestConfigs(shape, collector);
	}
	static middle::ComponentReflectionMethods refMethods = 
	{
		&serialize,
		&deserialize,
		&getFields
	};
	static middle::ComponentRegistrar<EcsPerformanceTestConfigs>reg("EcsPerformanceTestConfigs", refMethods);
}