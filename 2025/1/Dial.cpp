#include "Dial.hpp"
#include <cstdint>
#include <print>

Dial::Dial(uint32_t initialPosition, uint32_t size)
    : initialPosition_(initialPosition)
    , currentPosition_(initialPosition)
    , size_(size)
{
}

int Dial::turnLeft(uint32_t shift)
{
    auto afterModulo = shift % size_;

    std::print("Dial::{0}, current position: {1} shift: {2}, afterModulo: {3}\n", __func__,
               currentPosition_, shift, afterModulo);

    if (afterModulo > currentPosition_)
    {
    }
    else
    {
        currentPosition_ = currentPosition_ - afterModulo;
    }

    // return afterModulo;
    // return 0;
    // return 32;
    return currentPosition_;
}

int Dial::turnRight(uint32_t shift)
{
    auto afterModulo = shift % size_;
}
