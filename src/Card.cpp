#include "Card.h"
#include <iostream>

Card::Card(const Rank &rank,const Suit &suit)
    : m_rank{rank}, m_suit{suit}
{

}

char Card::rank() const
{
    switch(m_rank)
    {
    case Rank::RANK_2:
        return '2';
    case Rank::RANK_3:
        return '3';
    case Rank::RANK_4:
        return '4';
    case Rank::RANK_5:
        return '5';
    case Rank::RANK_6:
        return '6';
    case Rank::RANK_7:
        return '7';
    case Rank::RANK_8:
        return '8';
    case Rank::RANK_9:
        return '9';
    case Rank::RANK_10:
        return 'T';
    case Rank::RANK_JACK:
        return 'J';
    case Rank::RANK_QUEEN:
        return 'Q';
    case Rank::RANK_KING:
        return 'K';
    case Rank::RANK_ACE:
        return 'A';
    default:
        return 'X';
    }
}

int Card::value() const
{
    switch(m_rank)
    {
    case Rank::RANK_2:
        return 2;
    case Rank::RANK_3:
        return 3;
    case Rank::RANK_4:
        return 4;
    case Rank::RANK_5:
        return 5;
    case Rank::RANK_6:
        return 6;
    case Rank::RANK_7:
        return 7;
    case Rank::RANK_8:
        return 8;
    case Rank::RANK_9:
        return 9;
    case Rank::RANK_10:
    case Rank::RANK_JACK:
    case Rank::RANK_QUEEN:
    case Rank::RANK_KING:
        return 10;
    case Rank::RANK_ACE:
        return 11;
    default:
        return 0;
    }
}


char Card::suit() const
{
    switch(m_suit)
    {
    case Suit::SUIT_CLUB:
        return 'C';
    case Suit::SUIT_DIAMOND:
        return 'D';
    case Suit::SUIT_HEART:
        return 'H';
    case Suit::SUIT_SPADE:
        return 'S';
    default:
        return 'X';
    }
}

void Card::print() const
{
    std::cout << rank() << suit();
}

bool Card::isAce() const
{
    return m_rank == Card::Rank::RANK_ACE;
}
