//
// Created by Paul Brown on 4/5/16.
//

#include "Piece.h"

namespace Gaming {

    unsigned int __idGen = 0;


    Piece::Piece(const Game &g, const Position &p) :
            __game(g), __position(p) {

        __finished = false;
        __turned = false;
        __id = __idGen++;

    }

    std::ostream &Gaming::operator<<(std::ostream &os, const Piece &piece) {

        piece.print(os);
        return os;
    }
}
