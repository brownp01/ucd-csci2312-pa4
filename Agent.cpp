//
// Created by Paul Brown on 4/5/16.
//

#include "Agent.h"
#include "Resource.h"

namespace Gaming {


    Agent::Agent(const Game &g, const Position &p, double energy): Piece (g,p) {

        __energy = energy;
    }
}
