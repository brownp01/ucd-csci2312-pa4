//
// Created by Paul Brown on 4/5/16.
//

#include "Simple.h"

namespace Gaming{


    Simple::Simple(const Game &g, const Position &p, double energy) {

    }

    void Simple::print(std::ostream &os) const {

    }

    ActionType Simple::takeTurn(const Surroundings &s) const {
        return S;
    }
}