#include "Executor.h"
#include "Table.h"
#include <iostream>

void printTable(const std::vector<Row>& rows){
    for(const Row& row : rows){
        std::cout<<row.id<<"\t"<<row.username<<"\t"<<row.email<<"\n";
    }
}

ExecuteResult executeStatement(const Statement& statement, Table& table){
    switch(statement.type){
        case StatementType::Insert :
            std::cout<<"Executing insert operation\n";
            table.insert(statement.row);
            return ExecuteResult::Success;
        case StatementType::Select :
            std::cout<<"Executing Select operation\n";
            printTable(table.getAllRows());
            return ExecuteResult::Success;
    }
    return ExecuteResult::Success;
}