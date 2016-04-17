//
// Created by Paul Brown on 4/5/16.
//

#include "AggressiveAgentStrategy.h"
#include "Game.h"

namespace Gaming{

    const double DEFAULT_AGGRESSION_THRESHOLD = Game::STARTING_AGENT_ENERGY * 0.75;


    Gaming::AggressiveAgentStrategy::AggressiveAgentStrategy(double agentEnergy) {

        __agentEnergy = agentEnergy;

    }

    ActionType AggressiveAgentStrategy::operator()(const Surroundings &s) const {

        return STAY;
    }
}



