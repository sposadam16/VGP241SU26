#pragma once

#include <cstddef>
#include <cstdlib>
#include <string>

#include <Array.h>

enum Stats
{
    Health,
    Attack,
    Defense,
    Stamina,
    Speed,
};

class Player
{
public:
    Player()
    {
    }

    Player(std::string name)
    {
        mName = name;
        Initialize();
    }

    void Initialize()
    {
        mStats[Health] = 100;

        for (int stat = Attack; stat <= Speed; ++stat)
        {
            mStats[stat] = (std::rand() % 5) + 1;
        }
    }

    std::string GetName() const
    {
        return mName;
    }

    int GetStat(Stats stat) const
    {
        return mStats[stat];
    }

private:
    std::string mName;
    Array<int, 5> mStats;
};
