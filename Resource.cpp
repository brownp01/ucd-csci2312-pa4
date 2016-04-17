//
// Created by Paul Brown on 4/5/16.
//

#include "Resource.h"

namespace Gaming{


    Resource::Resource(const Game &g, const Position &p, double capacity) {

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
        return <#initializer#>;
    }
}