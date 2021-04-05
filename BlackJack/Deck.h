#ifndef DECK_H
#define DECK_H

#include<array>

#include "Card.h"

class Deck
{
public:
    using deck_type = std::array<Card, 52>;
    using index_type = deck_type::size_type;
private:
    deck_type m_deck{};
    std::size_t m_cardIndex{};
public:
    Deck();
    void print() const;
    void shuffle();
    const Card& dealCard();
};

#endif // DECK_H
