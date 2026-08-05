#include "Table.h"
#include "Constants.hpp"
#include "Serialization.hpp"
#include <cassert>

// const std::vector<Row>& Table::rows() const{
//     return rows_;
// }

// void Table::insert(const Row& row){
//     rows_.push_back(row);
// }

void Table::insert(const Row& row){
    std::size_t pageNo = rowCount_ / PageLayout::ROWS_PER_PAGE;
    std::byte* page = pager_.getPage(pageNo);
    uint32_t pageRowCount = readRowCount(page);
    uint32_t newRowOffset = pageRowSlotOffset(pageRowCount);
    Serialization::serialize(row, page+newRowOffset);
    pageRowCount++;
    writeRowCount(page, pageRowCount);
    rowCount_++;
}

const std::vector<Row> Table::getAllRows() const{
    std::vector<Row> rows(rowCount_);
    //iterate throught allocated pages 
    std::size_t index=0;   
    for(std::size_t i=0; i<pager_.pageCount(); i++){
        //get rows from each page by getting row count and iterating trough them
        assert(index < rowCount_);
        const std::byte* page = pager_.getPage(i);
        std::size_t rowCount = readRowCount(page);
        for(std::size_t j=0; j<rowCount; j++){
            Serialization::deserialize(page + pageRowSlotOffset(j), rows[index]);
            index++;
        }
    }
    return rows;
}

std::size_t Table::getRowCount(){
    return rowCount_;
}