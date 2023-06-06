#ifndef PIECES_HPP
#define PIECES_HPP

#include "bitboard.hpp"

namespace Chess{

    enum Pieces{
        WPAWN = 0,
        BPAWN,
        WKNIGHT,
        BKNIGHT,
        WBISHOP,
        BBISHOP,
        WROOK,
        BROOk,
        WQUEEN,
        BQUEEN,
        WKING,
        BKING,
    };

    class WhitePawnBoard : public BitBoard{
        public:
            WhitePawnBoard();
            uint64_t pseudolegal_moves(uint64_t opposing_pieces);
    };

    class BlackPawnBoard : public BitBoard{
        public:
            BlackPawnBoard();
            uint64_t pseudolegal_moves(uint64_t opposing_pieces);
    };
/*
    class KnightBoard : public BitBoard{
        public:
            uint64_t pseudolegal_moves(uint64_t opposing_pieces);
    };

    class BishopBoard : public BitBoard{
        public:
            uint64_t pseudolegal_moves(uint64_t opposing_pieces);
    };

    class RookBoard : public BitBoard{
        public:
            uint64_t pseudolegal_moves(uint64_t opposing_pieces);
    };

    class QueenBoard : public BitBoard{
        public:
            uint64_t pseudolegal_moves(uint64_t opposing_pieces);
    };

    class KingBoard : public BitBoard{
        public:
            uint64_t pseudolegal_moves(uint64_t opposing_pieces);
    };
*/

}


#endif