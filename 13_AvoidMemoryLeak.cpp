#include <iostream>
#include <vector>

class DataChunk{
    int* buffer;
    size_t size;

public:
    DataChunk(size_t s) : size(s) {
        buffer = new int[size];
        std::cout<<"Allocated "<<size*sizeof(int)/1024<<" KB"<<std::endl;
    }

    ~DataChunk(){
        delete[] buffer;
        std::cout<<"Freed "<<size*sizeof(int)/1024<<" KB"<<std::endl;
    }

    void fill(int value){
        for(size_t i = 0; i < size; i++){
            buffer[i] = value;
        }
    }
};

int main()
{
    for(int i = 0; i < 1000; i++){
        DataChunk chunk(10000); // ~40 KB per chunk
        chunk.fill(i);
    }

    std::cout<<"Done."<<std::endl;
    std::cout<<std::endl<<std::endl;

    return 0;
}