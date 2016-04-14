//
// Created by Paul Brown on 4/5/16.
//

#include "Game.h"
#include "Advantage.h"
#include "Strategic.h"
#include "Simple.h"
#include "Food.h"

namespace Gaming {

    unsigned int NUM_INIT_AGENT_FACTOR = 4;
    unsigned int NUM_INIT_RESOURCE_FACTOR = 2;
    int MIN_WIDTH = 3;
    int MIN_HEIGHT = 3;
    double STARTING_AGENT_ENERGY = 20;
    double STARTING_RESOURCE_CAPACITY = 10;


    void Game::populate() {

        __numInitAgents = (__width * __height) / NUM_INIT_AGENT_FACTOR;
        __numInitResources = (__width * __height) / NUM_INIT_RESOURCE_FACTOR;
        unsigned int numStrategic = __numInitAgents / 2;
        unsigned int numSimple = __numInitAgents - numStrategic;
        unsigned int numAdvantages = __numInitResources / 4;
        unsigned int numFoods = __numInitResources - numAdvantages;

        std::default_random_engine gen;
        std::uniform_int_distribution<int> d(0, __width * __height);

        while (numStrategic > 0) {
            int i = d(gen);
            if (__grid[i] == nullptr) {
                Position pos(i / __width, i % __width);
                __grid[i] = new Strategic(*this, pos, Game::STARTING_AGENT_ENERGY);
                numStrategic --;
            }
        }

        while (numSimple > 0) {
            int i = d(gen);
            if (__grid[i] == nullptr) {
                Position pos(i / __width, i % __width);
                __grid[i] = new Simple(*this, pos, Game::STARTING_AGENT_ENERGY);
                numStrategic --;
            }
        }

        while (numAdvantages > 0) {
            int i = d(gen);
            if (__grid[i] == nullptr) {
                Position pos(i / __width, i % __width);
                __grid[i] = new Advantage(*this, pos, Game::STARTING_RESOURCE_CAPACITY;
                numStrategic --;
            }
        }

        while (numFoods > 0) {
            int i = d(gen);
            if (__grid[i] == nullptr) {
                Position pos(i / __width, i % __width);
                __grid[i] = new Food(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
                numStrategic --;
            }
        }
    }

    Game::Game() : __grid(MIN_WIDTH * MIN_HEIGHT, nullptr){

        __numInitAgents = 0;
        __numInitResources = 0;
        __width = MIN_WIDTH;
        __height = MIN_HEIGHT;
        __round = 0;
        __status = NOT_STARTED;
        __verbose = false;

    }
}