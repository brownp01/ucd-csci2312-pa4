//
// Created by Paul Brown on 4/5/16.
//

#include "Strategic.h"

namespace Gaming{

    const char STRATEGIC_ID = 'T';


    Strategic::Strategic(const Game &g, const Position &p, double energy, Strategy *s) :
              Agent(g, p, energy){

        __strategy = s;

    }

    void Strategic::print(std::ostream &os) const {

        os << STRATEGIC_ID << __id;

    }

    ActionType Strategic::takeTurn(const Surroundings &s) const {

        return (*__strategy((s);
    }
}