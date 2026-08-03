#pragma once
#include "Row.h"
#include <cstring>
#include <cstddef>

namespace Serialization{
void serialize(const Row& row, std::byte* destination);
void deserialize(const std::byte* src, Row& row);
};