#include "chessengine.hpp"

using namespace Chess;

int main(){   
    BlackKnightBoard w; 
    


    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << w.value_at((7-i)*8 + j) << " ";
        }
        std::cout << std::endl;
    }
    
}