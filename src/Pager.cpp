#include "Pager.h"
#include "Constants.hpp"
#include <cassert>

std::byte* Pager::getPage(std::size_t pageNumber){
    //return ptr to page, if not exist allocate memory for the page and return ptr
    if(pageNumber >= pages_.size()){
        pages_.resize(pageNumber+1);
    }
    return pages_[pageNumber].data();
}

const std::byte* Pager::getPage(std::size_t pageNumber) const{
    //return ptr to page, if not exist allocate memory for the page and return ptr
    // if(pageNumber >= pages_.size()){
    //     pages_.resize(pageNumber+1);
    //     return pages_[pageNumber].data();
    // }
    assert(pageNumber < pages_.size());
    return pages_[pageNumber].data();
}

std::size_t Pager::pageCount() const{
    return pages_.size();
}

std::uint32_t readRowCount(const std::byte* page){
    uint32_t count;
    memcpy(&count, page+PageLayout::ROW_COUNT_OFFSET, sizeof(count));
    return count;
}

void writeRowCount(std::byte* page, std::uint32_t count){
    memcpy(page + PageLayout::ROW_COUNT_OFFSET, &count, sizeof(count));
}

std::size_t pageRowSlotOffset(size_t rowIndex){
    return PageLayout::ROW_OFFSET + rowIndex*RecordLayout::ROW_SIZE;
}