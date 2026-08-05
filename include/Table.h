#pragma once
#include "Row.h"
#include "Pager.h"
#include <vector>

class Table{
    Pager pager_;
    std::size_t rowCount_ = 0;
public:
    void insert(const Row& row);
    // const std::vector<Row>& rows() const;
    const std::vector<Row> getAllRows() const;
    std::size_t getRowCount();
};
