#include "bitboard.hpp"

using namespace Chess;

int main(void){   
    WhitePawnBoard b; 
    std::cout << b.get_board() << std::endl;


    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << value_at(b.get_board(), (7-i)*8 + j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "\n\n";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << value_at(b.pseudolegal_moves(0ULL), (7-i)*8 + j) << " ";
        }
        std::cout << std::endl;
    }
    
}