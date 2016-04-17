//
// Created by Paul Brown on 4/5/16.
//

#include "Food.h"

namespace Gaming{

    const char FOOD_ID = 'F';

    Food::Food(const Game &g, const Position &p, double capacity) : Resource(g, p, capacity) {

    }

    void Food::print(std::ostream &os) const {

    }
}