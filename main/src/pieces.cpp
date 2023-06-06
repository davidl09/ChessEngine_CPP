#include "pieces.hpp"


namespace Chess{

    WhitePawnBoard::WhitePawnBoard()
    : BitBoard(){
        this->board |= ((uint64_t)0x00000000000000ff << 8 * 1);
    }

    uint64_t WhitePawnBoard::pseudolegal_moves(uint64_t opposing_pieces){
        uint64_t empty = (this->board << 8) & ~opposing_pieces;
        uint64_t attack = ((this->board << 7) | (this->board << 9)) & opposing_pieces;
        uint64_t start = (((uint64_t)0xff << 8) & this->board) << 16;
        return empty | attack | start;
    }

    BlackPawnBoard::BlackPawnBoard()
    : BitBoard(){
        this -> board |= ((uint64_t)0x00000000000000ff << 8 * 6);
    }

    uint64_t BlackPawnBoard::pseudolegal_moves(uint64_t opposing_pieces){
        uint64_t empty = (this->board >> 8) & ~opposing_pieces;
        uint64_t attack = ((this->board >> 7) | (this->board >> 9)) & opposing_pieces;
        uint64_t start = (((uint64_t)0xff >> 8) & (this->board) >> 16);
        return empty | attack | start;
    }

}