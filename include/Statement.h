#pragma once
#include <string>
#include "Row.h"
enum class StatementType{
    Insert,
    Select
};

enum class PrepareResult{
    Success,
    UnrecognizedStatement,
    SyntaxError
    //later SyntaxError, Missing values etc
};

struct Statement{
    StatementType type;
    //later row, table_name, where condns, order by, limit etc
    Row row;

};

PrepareResult prepareStatement(const std::string& input, Statement& statement);