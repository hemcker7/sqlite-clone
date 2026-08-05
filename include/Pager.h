#pragma once
#include <vector>
#include <array>
#include <cstring>
#include "Constants.hpp"

// inline constexpr std::size_t PAGE_SIZE = 4096;

class Pager{
    std::vector<std::array<std::byte, PageLayout::PAGE_SIZE>> pages_;
public:
    std::byte* getPage(std::size_t pageNumber);
    const std::byte* getPage(std::size_t pageNumber) const;
    std::size_t pageCount() const;
};

std::uint32_t readRowCount(const std::byte* page);

void writeRowCount(std::byte* page, std::uint32_t count);

std::size_t pageRowSlotOffset(size_t rowIndex);