#include "bitboard.hpp"

namespace Chess{

    class WhitePawnBoard : public BitBoard{
        public:
            constexpr WhitePawnBoard()
            : BitBoard((uint64_t)0xff << 8 * 1)
            {}

            uint64_t pseudolegal_moves(uint64_t opposing_pieces, uint64_t friend_pieces)
            {
                uint64_t empty = (this->board << 8) & ~(opposing_pieces | friend_pieces);
                uint64_t attack = ((this->board << 7) | (this->board << 9)) & opposing_pieces & ~friend_pieces;
                uint64_t start = ((((uint64_t)0xff << 8) & this->board) << 16) & ~(opposing_pieces | friend_pieces);
                return empty | attack | start;
            }
    };

    class BlackPawnBoard : public BitBoard{
        public:
            constexpr BlackPawnBoard()
            : BitBoard((uint64_t)0xff << 8 * 6)
            {}

            uint64_t pseudolegal_moves(uint64_t opposing_pieces, uint64_t friend_pieces){
                uint64_t empty = (this->board >> 8) & ~opposing_pieces;
                uint64_t attack = ((this->board >> 7) | (this->board >> 9)) & opposing_pieces;
                uint64_t start = (((uint64_t)0xff >> 8) & (this->board) >> 16);
                return empty | attack | start;
            }
    };
}