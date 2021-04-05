#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"

class Player
{
private:
    int m_score{};
    int m_aces{};
public:
    const Card& drawCard(Deck &deck);
    int score() const;
    bool isBusted() const;
};

#endif // PLAYER_H
