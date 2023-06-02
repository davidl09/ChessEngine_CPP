#include "chessengine.hpp"

using namespace Chess;

int main(void){   
    WhitePawnBoard b; 
    std::cout << b.get_board() << std::endl;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << b.value_at((7-i)*8 + j) << " ";
        }
        std::cout << std::endl;
    }
    
}