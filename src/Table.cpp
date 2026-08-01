#include "Table.h"

const std::vector<Row>& Table::rows() const{
    return rows_;
}

void Table::insert(const Row& row){
    rows_.push_back(row);
}