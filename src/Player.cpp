#include "Player.h"
#include <iostream>

const Card& Player::drawCard(Deck &deck)
{
    const Card& card = deck.dealCard();

    if (card.isAce())
    {
        ++m_aces;
    }
    m_score += card.value();

    if(m_score > 21 && m_aces)
    {
        m_score -= 10;
        --m_aces;
    }
    return card;
}

int Player::score() const
{
    return m_score;
}

bool Player::isBusted() const
{
    return m_score > 21;
}
