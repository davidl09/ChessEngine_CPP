#include "bitboard.hpp"

namespace Chess{

    typedef uint64_t u64;

    BitBoard::BitBoard(){
        this->board = 0ULL;
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

    //masks
    static constexpr uint64_t rank_mask(const int rank){
        assert(rank >= 0 && rank < 8);
        return (uint64_t)255 << rank;
    }

    static constexpr uint64_t file_mask(const int file){
        assert(file >= 0 && file < 8);
        return (uint64_t)101010101010101 << file;
    }

    static constexpr uint64_t right_diag_mask(const int rank_file){
        
    }
}