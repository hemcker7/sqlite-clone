#pragma once
#include "Row.h"
#include <vector>

class Table{
    std::vector<Row> rows_;
public:
    void insert(const Row& row);
    const std::vector<Row>& rows() const;
};
