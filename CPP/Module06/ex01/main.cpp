#include "Serializer.hpp"

int main() {
    Data originalData;
    originalData.name = "Example Data";
    originalData.value = 42;

    std::cout << "Original Data:" << std::endl;
    std::cout << "Name: " << originalData.name << ", Value: " << originalData.value << std::endl;

    uintptr_t raw = Serializer::serialize(&originalData);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data:" << std::endl;
    std::cout << "Name: " << deserializedData->name << ", Value: " << deserializedData->value << std::endl;

    return 0;
}
