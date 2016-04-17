//
// Created by Paul Brown on 4/5/16.
//

#include "Resource.h"
#include "Agent.h"

namespace Gaming{

    const double Resource::RESOURCE_SPOIL_FACTOR = 1.2;

    Resource::Resource(const Game &g, const Position &p, double capacity): Piece(g, p) {

        this->__capacity = capacity;
    }

    double Resource::consume() {
        return 0;
    }

    void Resource::age() {

    }

    ActionType Resource::takeTurn(const Surroundings &s) const {

        return STAY;
    }

    Piece &Resource::operator*(Piece &other) {

        return other.interact(this);
    }

    Piece &Resource::interact(Agent *agent) {

        agent->addEnergy(this->getCapacity());
        this->finish();

        return *this;
    }

    Piece &Resource::interact(Resource *resource) {
        return *this;
    }
}