//to comile use the command below
// g++ -std=c++20 -I../include serialization_test.cpp ../src/Serialization.cpp 

#include "../include/Table.h"
#include "../include/Serialization.hpp"
#include "../include/Constants.hpp"
#include <iostream>
#include<array>


int main(){
    Row row={2, "aaaAAAAAAAAAAAAAAAAAAAAAAAAAAAAbbb", "aaaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
    std::array<std::byte, RecordLayout::ROW_SIZE> buffer;
    std::fill(buffer.begin(), buffer.end(), std::byte{0xAA});
    Serialization::serialize(row, buffer.data());
    buffer[10]=(std::byte)'X';
    Row newRow;
    Serialization::deserialize(buffer.data(), newRow);
    std::cout<<newRow.id<<"\n"<<newRow.username<<"\n"<<newRow.email<<"\n";
    return 0;
}