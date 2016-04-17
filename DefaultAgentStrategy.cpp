//
// Created by Paul Brown on 4/5/16.
//

#include "DefaultAgentStrategy.h"

namespace Gaming{


    DefaultAgentStrategy::DefaultAgentStrategy() {

    }

    ActionType DefaultAgentStrategy::operator()(const Surroundings &s) const {
        return S;
    }
}