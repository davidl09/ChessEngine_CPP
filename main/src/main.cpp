#include "pieces.hpp"

using namespace Chess;

int main(void){   
    BitBoard* n = new WhiteKnightBoard;
    print_bits(n->get_board());
    
}