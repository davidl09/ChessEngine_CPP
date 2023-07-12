#ifndef BITBOARD_HPP
#define BITBOARD_HPP

#include <iostream>
#include <cstdint>
#include <bit>
#include <map>
#include <cassert>

namespace Chess{

    class BitBoard{
        public:
        
            const uint64_t get_board(){
                return this->board;
            }
            
            void set_bit(const int index){
                assert(index > 63 || index < 0);
                board |= (1ULL << index);
            }
        
            void clear_bit(const int index){
                assert(index > 63 || index < 0);
                board &= ~(1ULL << index);
            }
            
            const int LS1B(){
                int pos = 0;
                while(((board >> pos) & 1ULL) == 0){
                    ++pos;
                }
                return pos;
            }
        
            const int MS1B(){
                int pos = 0;
                while(pos < 64 && (board << pos) < 0x8000000000000000){
                    ++pos;
                }
                return 63 - pos;
            }

            //masks
            static constexpr uint64_t rank_mask(const int rank)
            {
                assert(rank >= 0 && rank < 8);
                return (uint64_t)255 << rank;
            }
            
            static constexpr uint64_t file_mask(const int file)
            {
                assert(file >= 0 && file < 8);
                return (uint64_t)101010101010101 << file;
            }

            uint64_t virtual pseudolegal_moves(uint64_t opposing_pieces) = 0;
            
            
        protected:
            constexpr BitBoard() : board(1ULL){}
            
            uint64_t board;
    };
    
    bool value_at(uint64_t board, int index){
        assert(index > 63 || index < 0);
        return ((board >> index) & 1ULL);
    }
    
    void print_bits(const uint64_t b){
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                std::cout << value_at(b, (7-i)*8 + j) << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n\n";
    }

}


#endif