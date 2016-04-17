//
// Created by Paul Brown on 4/5/16.
//

#include "Exceptions.h"

namespace Gaming{


    void GamingException::setName(std::string name) {

        __name = name;

    }

    std::ostream &Gaming::operator<<(std::ostream &os, const GamingException &ex) {
        return <#initializer#>;
    }

    DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height) {

    }

    unsigned DimensionEx::getExpWidth() const {

    }

    unsigned DimensionEx::getExpHeight() const {
        return 0;
    }

    unsigned DimensionEx::getWidth() const {
        return 0;
    }

    unsigned DimensionEx::getHeight() const {
        return 0;
    }

    void InsufficientDimensionsEx::__print_args(std::ostream &os) const {

    }

    InsufficientDimensionsEx::InsufficientDimensionsEx(unsigned minWidth, unsigned minHeight, unsigned width,
                                                       unsigned height) {

    }

    void OutOfBoundsEx::__print_args(std::ostream &os) const {

    }

    OutOfBoundsEx::OutOfBoundsEx(unsigned maxWidth, unsigned maxHeight, unsigned width, unsigned height) {

    }

    void PositionEx::__print_args(std::ostream &os) const {

    }

    PositionEx::PositionEx(unsigned x, unsigned y) {

    }

    PositionNonemptyEx::PositionNonemptyEx(unsigned x, unsigned y) {

    }

    PositionEmptyEx::PositionEmptyEx(unsigned x, unsigned y) {

    }

    void PosVectorEmptyEx::__print_args(std::ostream &os) const {

    }

    PosVectorEmptyEx::PosVectorEmptyEx() {

    }
}

