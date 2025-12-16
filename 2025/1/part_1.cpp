#include <cassert>
#include <cstdio>
#include <regex>
#include <print>

import filesystem;

enum class Direction
{
    Left,
    Right
};

int handleDialRotation(Direction direction, uint32_t currentPosition, uint32_t offset)
{
    uint32_t result = 0;

    if (direction == Direction::Left)
    {
        if (offset > currentPosition)
        {
            if ((currentPosition + offset) >= 100)
            {
                auto diff = (currentPosition + offset) % 100;
                result    = 100 - diff;
            }
            else
            {
                auto diff = offset - currentPosition;
                result    = 100 - diff;
            }
        }
        else
        {
            result = currentPosition - offset;
        }
    }
    else
    {
        if ((currentPosition + offset) >= 100)
        {
            auto diff = (currentPosition + offset) % 100;
            result    = 0 + diff;
        }
        else
        {
            result = currentPosition + offset;
        }

        return result;
    }

    return result;
}

// int sub(uint32_t position, uint32_t offset)
// {
//     uint32_t result = 0;

//     if (offset > position)
//     {
//         auto diff = offset - position;
//     }
//     else
//     {
//         result = position - offset;
//     }

//     // if (offset > position)
//     // {
//     //     auto diff = offset - position;
//     //     result    = 100 - diff;
//     // }
//     // else
//     // {
//     //     result = position - offset;
//     // }

//     return result;
// }

// int add(uint32_t position, uint32_t offset)
// {
//     uint32_t result = 0;

//     if ((position + offset) >= 100)
//     {
//         auto diff = (position + offset) - 100;
//         result    = 0 + diff;
//     }
//     else
//     {
//         result = position + offset;
//     }

//     return result;
// }

int main()
{
    auto reader = filesystem::ReadFile("../2025/1/input");
    // auto reader = filesystem::ReadFile("../2025/1/test_input");
    auto lines = reader.readLines();

    uint32_t password = 0;
    uint32_t position = 50;
    uint32_t offset   = 0;

    static const auto r = std::regex(R"([0-9]+)");
    std::smatch       m;

    for (auto&& line : lines)
    {
        if (std::regex_search(line, m, r))
        {
            assert(m.size() == 1);
            offset = std::stoi(m[0].str());
        }

        if (line.starts_with("L"))
        {
            position = handleDialRotation(Direction::Left, position, offset);
        }
        else if (line.starts_with("R"))
        {
            position = handleDialRotation(Direction::Right, position, offset);
        }
        else
        {
            std::print("Wrong value! {0}", line);
        }

        if (position == 0)
        {
            password++;
        }

        std::print("The dial is rotated {0} to point at {1}\n", line, position);
    }

    std::print("\nResult {0}, password {1}\n", position, password);

    return 0;
}