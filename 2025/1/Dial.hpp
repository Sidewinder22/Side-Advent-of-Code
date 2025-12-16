#pragma once

#include <cstdint>

class Dial
{
public:
    explicit Dial(uint32_t initialPosition, uint32_t size);
    int turnLeft(uint32_t shift);
    int turnRight(uint32_t shift);

private:
    uint32_t initialPosition_;
    uint32_t currentPosition_;
    uint32_t size_;
};
