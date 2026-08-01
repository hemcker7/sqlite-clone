#include "InputBuffer.h"
#include "MetaCommand.h"
#include "Statement.h"
#include "Executor.h"
// #include "Table.h"
#include <iostream>

int main(){
    InputBuffer inputBuffer;
    MetaCommandHandler metaCommandHandler;
    Table table;
    while(true){
        inputBuffer.printPrompt();
        if(!inputBuffer.readInput()){
            std::cout<<"Input Read Error!\n";
            break;
        }
        const std::string& input = inputBuffer.getInput();
        if(!input.empty() && input[0]=='.'){
            switch(metaCommandHandler.execute(input)){
                case MetaCommandResult::Exit :
                    return 0;
                case MetaCommandResult::Success :
                    continue;
                case MetaCommandResult::Unrecognized :
                    std::cout<<"Unrecognized MetaCommand : "<<input<<"\n";
                    continue;
            }
        }
        
        Statement statement;
        PrepareResult result =  prepareStatement(input, statement);
        if(result == PrepareResult::UnrecognizedStatement){
            std::cout<<"Unrecognized SQL statement.\n";
            continue;
        }
        else if(result == PrepareResult::Success){
            executeStatement(statement, table);
        }
        else if(result == PrepareResult::SyntaxError){
            std::cout<<"Syntax Error!\n";
        }
    }
    return 0;
}