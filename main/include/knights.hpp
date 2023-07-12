#include "bitboard.hpp"

namespace Chess
{
    class WhiteKnightBoard : public BitBoard{
        public:
            constexpr WhiteKnightBoard()
            : BitBoard((0x1ULL << 1) | (0x1ULL << 6) | (0x1ULL << 57) | (0x1ULL << 62)) {}

            uint64_t pseudolegal_moves(uint64_t opposing_pieces, uint64_t friend_pieces)
            {

            }
    };
} // namespace Chess
