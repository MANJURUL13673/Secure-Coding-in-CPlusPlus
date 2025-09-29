#include <iostream>
#include <fstream>

void processInput(const std::string& input) {
    if(input.empty()){
        throw std::invalid_argument("Input cannot be empty");
    }
}  

void loadFile(const std::string& filename) {
    std::ifstream file(filename);
    if(!file){
       throw std::ios_base::failure("Failed to open file: " );
    }
}

int main() {
    try{
        processInput(""); // will throw
        loadFile("nonexistent.txt"); // will throw
    }
    catch(const std::exception& ex){
        std::cerr<<"Error: "<<ex.what()<<std::endl;
        // Silent failure
    }

    std::cout<<std::endl<<std::endl;
    return 0;
}