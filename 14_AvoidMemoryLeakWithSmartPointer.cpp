#include <iostream>
#include <memory>

class DataChunk{
    std::unique_ptr<int[]> buffer; // use smart pointer to manage memory
    size_t size;

public:
    DataChunk(size_t s) : size(s){
        buffer = std::make_unique<int[]>(size); // allocate memory
        std::cout<<"Allocated "<<size*sizeof(int)/1024<<" KB"<<std::endl;
    }

    void fill(int value){
        for(size_t i = 0; i < size; i++){
            buffer[i] = value;
        }
    }
};

int main() {
    for(int i = 0; i < 1000; i++){
        DataChunk chunk(10000); // ~40 KB per chunk
        chunk.fill(i);
    }

    std::cout << "Done." << std::endl;
    return 0;
}