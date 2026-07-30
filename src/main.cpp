#include<iostream>
#include<string>

int main(){
    while(true){
        std::cout<<"db > ";
        std::string input;
        std::getline(std::cin, input);
        if(input == ".exit"){
            break;
        }
        std::cout<<"unrecognized command: "<<input<<"\n";

    }
    return 0;
}