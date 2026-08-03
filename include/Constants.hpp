#pragma once

namespace RecordLayout{
    inline constexpr size_t ID_SIZE = 4;
    inline constexpr size_t USERNAME_SIZE = 32;
    inline constexpr size_t EMAIL_SIZE = 255;
    inline constexpr size_t ID_OFFSET = 0;
    inline constexpr size_t USERNAME_OFFSET = ID_OFFSET + ID_SIZE;
    inline constexpr size_t EMAIL_OFFSET = USERNAME_OFFSET + USERNAME_SIZE;
    inline constexpr size_t ROW_SIZE = ID_SIZE + USERNAME_SIZE + EMAIL_SIZE;
};