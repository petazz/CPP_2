#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(void)
{
    Data test = {42};
    
    uintptr_t serialized = Serializer::serialize(&test);
    
    Data* restored = Serializer::deserialize(serialized);
    
    std::cout << "Original value: " << test.value << std::endl;
    std::cout << "Restored value: " << restored->value << std::endl;
    
    return 0;
}