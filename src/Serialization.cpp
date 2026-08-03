#include <string>
#include<algorithm>
#include "Constants.hpp"
#include "Serialization.hpp"

void Serialization::serialize(const Row& row, std::byte* destination){
    std::memset(destination, 0, RecordLayout::ROW_SIZE);
    std::memcpy(destination+RecordLayout::ID_OFFSET, &row.id, RecordLayout::ID_SIZE);
    std::memcpy(destination+RecordLayout::USERNAME_OFFSET, row.username.c_str(), std::min(static_cast<std::size_t>(row.username.size()), RecordLayout::USERNAME_SIZE));
    std::memcpy(destination+RecordLayout::EMAIL_OFFSET, row.email.c_str(), std::min(static_cast<std::size_t>(row.email.size()), RecordLayout::EMAIL_SIZE));
}


void Serialization::deserialize(const std::byte* src, Row& row){
    std::memcpy(&row.id, src, RecordLayout::ID_SIZE);
    std::size_t username_length = strnlen(reinterpret_cast<const char*>(src + RecordLayout::USERNAME_OFFSET), RecordLayout::USERNAME_SIZE);
    row.username = std::string(reinterpret_cast<const char*>(src + RecordLayout::USERNAME_OFFSET), username_length);
    std::size_t email_length = strnlen(reinterpret_cast<const char*>(src + RecordLayout::EMAIL_OFFSET), RecordLayout::EMAIL_SIZE);
    row.email = std::string(reinterpret_cast<const char*>(src+ RecordLayout::EMAIL_OFFSET), email_length);
}
