#include "chessengine.hpp"

using namespace Chess;

BitBoard::BitBoard(){
    this->board = 0ULL;
}

WhitePawnBoard::WhitePawnBoard()
: BitBoard(){
    this->board |= ((uint64_t)0xff << 8);
}

BlackPawnBoard::BlackPawnBoard() 
: BitBoard(){
    this->board |= ((uint64_t)0xff << 6 * 8);
}

WhiteKnightBoard::WhiteKnightBoard()
: BitBoard(){
    this->set_bit(1);
    this->set_bit(6);
}

BlackKnightBoard::BlackKnightBoard()
: BitBoard(){
    this->set_bit(62);
    this->set_bit(57);
}

uint64_t WhitePawnBoard::pseudolegal_moves(uint64_t pieces){ //to be continued
    return 0;
}

uint64_t BlackPawnBoard::pseudolegal_moves(uint64_t pieces){
    return 0;
}

uint64_t WhiteKnightBoard::pseudolegal_moves(uint64_t pieces){
    return 0;
}

uint64_t BlackKnightBoard::pseudolegal_moves(uint64_t pieces){
    return 0;
}

bool BitBoard::value_at(int index){
    if(index > 63 || index < 0){
        throw std::invalid_argument("Out of bounds access on BitBoard\n");
    }
    return ((board >> index) % 2);
}

void BitBoard::set_bit(int index){
    if(index > 63 || index < 0){
        throw std::invalid_argument("Out of bounds access on BitBoard\n");
    }
    board |= (1ULL << index);
}

void BitBoard::clear_bit(int index){
    if(index > 63 || index < 0){
        throw std::invalid_argument("Out of bounds access on BitBoard\n");
    }
    board &= ~(1ULL << index);
}

int BitBoard::LS1B(){
    int pos = 0;
    while((board >> pos) % 2 == 0){
        ++pos;
    }
    return pos;
}

int BitBoard::MS1B(){
    int pos = 0;
    while(pos < 64 && (board << pos) < 0x8000000000000000){
        ++pos;
    }
    return 63 - pos;
}

uint64_t BitBoard::get_board(){
    return this->board;
}

//Constructors


/*
BlackPawnBoard::BlackPawnBoard(){
    this->board = 0x0;
    this->board &= ((0xff) << 56);
}*/

void Board::print_board(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << this->piece_boards[0]->get_board() << " ";
        }
        std::cout << std::endl;
    }
}

