#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include <Vector.h>
#include "Player.h"

std::string RandomName()
{
    std::string names[] = {
        "Avery", "Blake", "Casey", "Drew", "Emery", "Finley", "Harper", "Jordan",
        "Kai", "Logan", "Morgan", "Nova", "Parker", "Quinn", "Riley", "Sage",
        "Taylor", "Val", "Winter", "Zion"
    };

    return names[std::rand() % 20];
}

void DisplayPlayer(Player& player)
{
    std::cout << player.GetName()
        << " | Health: " << player.GetStat(Health)
        << " | Attack: " << player.GetStat(Attack)
        << " | Defense: " << player.GetStat(Defense)
        << " | Stamina: " << player.GetStat(Stamina)
        << " | Speed: " << player.GetStat(Speed) << '\n';
}

void DisplayPlayers(Vector<Player>& players)
{
    for (std::size_t i = 0; i < players.Size(); ++i)
    {
        DisplayPlayer(players[i]);
    }
}

int CalculateScore(Player& attacker, Player& defender)
{
    return attacker.GetStat(Health) -
        ((defender.GetStat(Attack) * defender.GetStat(Stamina)) -
         (attacker.GetStat(Defense) * attacker.GetStat(Speed)));
}

int main()
{
    const int initialPlayerCount = 10;
    const int playersToRemove = 6;
    const int maxPlayerCount = 20;

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    Vector<Player> players;
    for (std::size_t i = 0; i < initialPlayerCount; ++i)
    {
        players.PushBack(Player(RandomName()));
    }

    std::cout << "Initial players:\n";
    DisplayPlayers(players);

    players.Resize(players.Size() - playersToRemove);
    std::cout << "\nAfter removing 6 players: " << players.Size() << " players remain.\n";

    std::cout << "\nNew players:\n";
    while (players.Size() < maxPlayerCount)
    {
        Player newPlayer = Player(RandomName());
        players.PushBack(newPlayer);
        DisplayPlayer(newPlayer);
    }

    std::size_t playerAIndex = std::rand() % players.Size();
    std::size_t playerBIndex = std::rand() % players.Size();
    while (playerAIndex == playerBIndex)
    {
        playerBIndex = std::rand() % players.Size();
    }

    Player& playerA = players[playerAIndex];
    Player& playerB = players[playerBIndex];
    int playerAScore = CalculateScore(playerA, playerB);
    int playerBScore = CalculateScore(playerB, playerA);

    std::cout << "\nFight: " << playerA.GetName() << " vs " << playerB.GetName() << '\n';
    std::cout << playerA.GetName() << " score: " << playerAScore << '\n';
    std::cout << playerB.GetName() << " score: " << playerBScore << '\n';

    if (playerAScore > playerBScore)
    {
        std::cout << "Winner: " << playerA.GetName() << '\n';
    }
    else if (playerBScore > playerAScore)
    {
        std::cout << "Winner: " << playerB.GetName() << '\n';
    }
    else
    {
        Player& winner = (std::rand() % 2 == 0) ? playerA : playerB;
        std::cout << "Tie! Coin flip winner: " << winner.GetName() << '\n';
    }
}
