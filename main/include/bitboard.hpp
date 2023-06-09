#ifndef BITBOARD_HPP
#define BITBOARD_HPP

#include <iostream>
#include <cstdint>
#include <bit>
#include <map>
#include <cassert>

namespace Chess{
    
    bool value_at(uint64_t board, int index);


    class BitBoard{
        public:
            virtual uint64_t get_board();
            bool value_at(int index);
            void set_bit(int index);
            void clear_bit(int index);
            int LS1B();
            int MS1B();

            //masks
            static constexpr uint64_t rank_mask(int rank);
            static constexpr uint64_t file_mask(int file);

            uint64_t virtual pseudolegal_moves(uint64_t opposing_pieces) = 0;
        protected:
            BitBoard();
            uint64_t board;
    };

}


#endif