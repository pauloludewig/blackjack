#include "Deck.h"
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <cassert>

Deck::Deck()
{
    index_type card{0};
    for(int i{0}; i < static_cast<int>(Card::Rank::MAX_RANKS); ++i)
    {
        for(int j{0}; j < static_cast<int>(Card::Suit::MAX_SUITS); ++j)
        {
            m_deck[card] = Card(static_cast<Card::Rank>(i), static_cast<Card::Suit>(j));
            ++card;
        }
    }
}


void Deck::print() const
{
    for(auto &c: m_deck)
    {
        c.print();
        std::cout << ' ';
    }
    std::cout << '\n';
}

void Deck::shuffle()
{
    static std::mt19937 mt{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
    std::shuffle(m_deck.begin(), m_deck.end(), mt);
    m_cardIndex = 0;
}

const Card& Deck::dealCard()
{
    assert(m_cardIndex < m_deck.size());
    return m_deck[m_cardIndex++];
}

