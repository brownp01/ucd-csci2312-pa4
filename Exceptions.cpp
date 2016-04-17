//
// Created by Paul Brown on 4/5/16.
//

#include "Exceptions.h"

namespace Gaming{


    void GamingException::setName(std::string name) {

        __name = name;

    }

    std::ostream &Gaming::operator<<(std::ostream &os, const GamingException &ex) {

        ex.__print_args(os);
        return os;
    }

    DimensionEx::DimensionEx(unsigned expWidth, unsigned expHeight, unsigned width, unsigned height) {

        __name = "DimensionsEX";
        __exp_width = expWidth;
        __exp_height = expHeight;
        __width = width;
        __height = height;

    }

    unsigned DimensionEx::getExpWidth() const {

        return __exp_width;

    }

    unsigned DimensionEx::getExpHeight() const {

        return __exp_height;
    }

    unsigned DimensionEx::getWidth() const {

        return __width;
    }

    unsigned DimensionEx::getHeight() const {

        return __height;
    }

    void InsufficientDimensionsEx::__print_args(std::ostream &os) const {

        os << getName() << ": " << "dimensions must be greater than " << getExpWidth() << "x"
        << getExpHeight() << ", user set to " << getWidth() << "x" << getHeight() << std::endl;

    }

    InsufficientDimensionsEx::InsufficientDimensionsEx(unsigned minWidth, unsigned minHeight, unsigned width,
                                                       unsigned height) :
                DimensionEx(minWidth, minHeight, width, height){

            setName("InsufficientDimensionsEx");

    }

    void OutOfBoundsEx::__print_args(std::ostream &os) const {

        os << getName() << ": " << "Position " << getHeight() << ", " << getWidth() << " is outside of the "
        << getExpWidth() << "x" << getExpHeight() << " game grid" << std::endl;

    }

    OutOfBoundsEx::OutOfBoundsEx(unsigned maxWidth, unsigned maxHeight, unsigned width, unsigned height)
        : DimensionEx(maxWidth, maxHeight, width, height){

        setName("OutOfBoundsEx");

    }

    void PositionEx::__print_args(std::ostream &os) const {

        os << getName() << ": " << "(" << __x << "," << __y << ")" << std::endl;

    }

    PositionEx::PositionEx(unsigned x, unsigned y) {

        __x = x;
        __y = y;

    }

    PositionNonemptyEx::PositionNonemptyEx(unsigned x, unsigned y) : PositionEx(x, y) {

        setName("PositionNonEmptyEx");

    }

    PositionEmptyEx::PositionEmptyEx(unsigned x, unsigned y) : PositionEx(x, y) {

        setName("PositionEmptyEx");

    }

    void PosVectorEmptyEx::__print_args(std::ostream &os) const {

    }

    PosVectorEmptyEx::PosVectorEmptyEx() {

        setName("PosVectoreEmptyEx");

    }
}

