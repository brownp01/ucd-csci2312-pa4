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
                __grid[i] = new Advantage(*this, pos, Game::STARTING_RESOURCE_CAPACITY);
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

    Game::Game(unsigned width, unsigned height, bool manual) {

        __width = width;
        __height = height;
        __round = 0;
        __status = NOT_STARTED;
        __verbose = false;

        if (manual == false)
            populate();

        else{
            __numInitResources = 0;
            __numInitAgents = 0;
        }

    }

    Game::~Game() {

    }

    unsigned int Game::getNumPieces() const {

        unsigned int pieces = 0;

        for (int i = 0; i < __grid.size(); i++){
            if (__grid[i] != nullptr)
                pieces++;
        }

        return pieces;
    }

    unsigned int Game::getNumAgents() const {

        unsigned int pieces = 0;

        for (int i = 0; i < __grid.size(); i++){
            if (__grid[i] != nullptr && (__grid[i]->getType() == SIMPLE) || __grid[i]->getType() == STRATEGIC)
                        pieces++;
        }

        return pieces;
    }

    unsigned int Game::getNumSimple() const {

        unsigned int pieces = 0;
        for (int i = 0; i < __grid.size(); i++){
            if (__grid[i] != nullptr && __grid[i]->getType() == SIMPLE)
                pieces++;
        }

        return pieces;
    }

    unsigned int Game::getNumStrategic() const {

        unsigned int pieces = 0;
        for (int i = 0; i < __grid.size(); i++) {
            if (__grid[i] != nullptr && __grid[i]->getType() == STRATEGIC)
                pieces++;
        }

        return pieces;
    }

    unsigned int Game::getNumResources() const {

        unsigned int pieces = 0;
        for (int i = 0; i < __grid.size(); i++) {
            if (__grid[i] != nullptr && (__grid[i]->getType() == FOOD || __grid[i]->getType() == ADVANTAGE))
                pieces++;
        }

        return pieces;
    }

    const Piece *Game::getPiece(unsigned int x, unsigned int y) const {
        return nullptr;
    }

    void Game::addSimple(const Position &position) {

    }

    void Game::addSimple(const Position &position, double energy) {

    }

    void Game::addSimple(unsigned x, unsigned y) {

    }

    void Game::addSimple(unsigned x, unsigned y, double energy) {

    }

    void Game::addStrategic(const Position &position, Strategy *s) {

    }

    void Game::addStrategic(unsigned x, unsigned y, Strategy *s) {

    }

    void Game::addFood(const Position &position) {

    }

    void Game::addFood(unsigned x, unsigned y) {

    }

    void Game::addAdvantage(const Position &position) {

    }

    void Game::addAdvantage(unsigned x, unsigned y) {

    }

    const Surroundings Game::getSurroundings(const Position &pos) const {
        return Gaming::Surroundings();
    }

    const ActionType Game::reachSurroundings(const Position &from, const Position &to) {
        return S;
    }

    bool Game::isLegal(const ActionType &ac, const Position &pos) const {
        return false;
    }

    const Position Game::move(const Position &pos, const ActionType &ac) const {
        return Gaming::Position();
    }

    void Game::round() {

    }

    void Game::play(bool verbose) {

    }

    std::ostream &Gaming::operator<<(std::ostream &os, const Game &game) {
        return <#initializer#>;
    }

    Game::Game(const Game &another) {

        __width = another.__width;
        __height = another.__height;
        __grid = another.__grid;
        __status = another.__status;

    }
}