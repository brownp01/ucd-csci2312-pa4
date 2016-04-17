//
// Created by Paul Brown on 4/5/16.
//

#include "Agent.h"
#include "Food.h"
#include "Advantage.h"

namespace Gaming {


    Agent::Agent(const Game &g, const Position &p, double energy): Piece (g, p) {

        __energy = energy;
    }

    void Agent::age() {

        __energy -= AGENT_FATIGUE_RATE;

    }

    Piece &Agent::operator*(Piece &other) {

        return other.interact(this);
    }

    Piece &Agent::interact(Agent *agent) {

        if (this->getEnergy() == agent->getEnergy()){
            this->finish();
            agent->finish();
        }

        else if (this->getEnergy() > agent->getEnergy()){
            this->addEnergy(-(agent->getEnergy()));
            agent->finish();
        }

        else{
            agent->addEnergy(-(this->getEnergy()));
            this->finish();
        }

        return *this;
    }

    Piece &Agent::interact(Resource *resource) {

        resource->interact(this);

        return *this;
    }
}
