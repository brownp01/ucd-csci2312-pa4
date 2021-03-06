//
// Created by Paul Brown on 4/5/16.
//

#include "Simple.h"

namespace Gaming{

    const char Simple::SIMPLE_ID = 'S';

    Simple::Simple(const Game &g, const Position &p, double energy) : Agent(g, p, energy) {

    }

    void Simple::print(std::ostream &os) const {

        os << SIMPLE_ID << __id;

    }

    ActionType Simple::takeTurn(const Surroundings &s) const {

        return STAY;
    }
}