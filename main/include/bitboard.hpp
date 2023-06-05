#ifndef CHESSENGINE_HPP
#define CHESSENGINE_HPP

#include <iostream>
#include <cstdint>
#include <bit>

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

    bool value_at(uint64_t board, int index);


    class BitBoard{
        public:
            virtual uint64_t get_board();
            bool value_at(int index);
            void set_bit(int index);
            void clear_bit(int index);
            int LS1B();
            int MS1B();

            uint64_t virtual pseudolegal_moves(uint64_t opposing_pieces) = 0;
        protected:
            BitBoard();
            uint64_t board;
    };

    class WhitePawnBoard : public BitBoard{
        public:
            WhitePawnBoard();
            uint64_t pseudolegal_moves(uint64_t opposing_pieces);
    };
/*
    class BlackPawnBoard : public BitBoard{
        public:
            BlackPawnBoard();
            uint64_t pseudolegal_moves(uint64_t opposing_pieces);
    };

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