#pragma once
#include <cstdint>

namespace RecordLayout{
    inline constexpr size_t ID_SIZE = sizeof(uint32_t);
    inline constexpr size_t USERNAME_SIZE = 32;
    inline constexpr size_t EMAIL_SIZE = 255;
    inline constexpr size_t ID_OFFSET = 0;
    inline constexpr size_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
    inline constexpr size_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
    inline constexpr size_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;
};

namespace PageLayout{
    inline constexpr std::size_t PAGE_SIZE = 4096;
    inline constexpr std::size_t HEADER_SIZE = sizeof(uint32_t);
    inline constexpr std::size_t ROW_COUNT_OFFSET = 0;
    inline constexpr std::size_t ROW_OFFSET = HEADER_SIZE;
    inline constexpr std::size_t ROWS_PER_PAGE = (PAGE_SIZE - HEADER_SIZE) / RecordLayout::ROW_SIZE;
}