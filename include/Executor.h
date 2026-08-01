#pragma once
#include "Statement.h"
#include "Table.h"

enum class ExecuteResult{
    Success,
    DuplicateKey,
    TableFull
};

ExecuteResult executeStatement(const Statement& statement, Table& table);