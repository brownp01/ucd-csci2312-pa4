//
// Created by Paul Brown on 4/5/16.
//

#include "Advantage.h"

namespace Gaming {

    const char ADVANTAGE_ID= 'D';
    const double ADVANTAGE_MULTI_FACTOR = 2.0;


    Advantage::Advantage(const Game &g, const Position &p, double capacity) : Resource(g, p, capacity) {

        __capacity *= ADVANTAGE_MULT_FACTOR;

    }

    void Advantage::print(std::ostream &os) const {

        os << ADVANTAGE_ID << __id;

    }

    double Advantage::getCapacity() const {

        return __capacity;
    }
}
