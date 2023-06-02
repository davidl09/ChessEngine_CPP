#include <iostream>
#include <cstdint>
#include <cmath>

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
    
    class BitBoard{
        public:
            BitBoard();
            BitBoard(uint64_t);
            uint64_t get_board();
            bool value_at(int index);
            void set_bit(int index);
            void clear_bit(int index);
            int LS1B();
            int MS1B();

            virtual BitBoard pseudolegal_moves();
        private:
            uint64_t board;
    };

    class WhitePawnBoard : public BitBoard{
        public:
            BitBoard pseudolegal_moves() override;
    };

    class BlackPawnBoard : public BitBoard{
        public:
            BitBoard pseudolegal_moves() override;
    };

    class KnightBoard : public BitBoard{
        public:
            BitBoard pseudolegal_moves() override;
    };

    class BishopBoard : public BitBoard{
        public:
            BitBoard pseudolegal_moves() override;
    };

    class RookBoard : public BitBoard{
        public:
            BitBoard pseudolegal_moves() override;
    };

    class QueenBoard : public BitBoard{
        public:
            BitBoard pseudolegal_moves() override;
    };

    class KingBoard : public BitBoard{
        public:
            BitBoard pseudolegal_moves() override;
    };

    class Board{
        public:
            Board();
            void print_board();
            bool white_in_check();
            bool black_in_check();
        private:
            BitBoard piece_boards[12];
    };


}