#include "Statement.h"
#include<sstream>

PrepareResult prepareStatement(const std::string& input, Statement& statement){
    if(input.starts_with("insert")){
        statement.type = StatementType::Insert;
        std::istringstream iss(input.substr(7));
        if(iss>>statement.row.id>>statement.row.username>>statement.row.email){
            return PrepareResult::Success;
        }
        else
            return PrepareResult::SyntaxError;
    }
    if(input.starts_with("select")){
        statement.type = StatementType::Select;
        return PrepareResult::Success;
    }
    return PrepareResult::UnrecognizedStatement;
}