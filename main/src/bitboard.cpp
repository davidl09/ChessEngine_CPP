#include "bitboard.hpp"

namespace Chess{
    BitBoard::BitBoard(){
        this->board = 0ULL;
    }

    WhitePawnBoard::WhitePawnBoard()
    : BitBoard(){
        this->board |= ((uint64_t)(0x00000000000000ff) << 8);
    }

    uint64_t WhitePawnBoard::pseudolegal_moves(uint64_t opposing_pieces){
        uint64_t empty = (this->board << 8) & ~opposing_pieces;
        uint64_t attack = ((this->board << 7) | (this->board << 9)) & opposing_pieces;
        uint64_t start = (((uint64_t)0xff << 8) & this->board) << 16;
        return empty | attack | start;
    }

    bool BitBoard::value_at(int index){
        if(index > 63 || index < 0){
            throw std::invalid_argument("Out of bounds access on BitBoard\n");
        }
        return ((board >> index) % 2);
    }

    bool value_at(uint64_t board, int index){
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

}