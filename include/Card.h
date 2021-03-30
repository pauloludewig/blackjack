#ifndef CARD_H
#define CARD_H


class Card
{
public:
    enum class Rank
    {
        RANK_2,
        RANK_3,
        RANK_4,
        RANK_5,
        RANK_6,
        RANK_7,
        RANK_8,
        RANK_9,
        RANK_10,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,

        MAX_RANKS
    };

    enum class Suit
    {
        SUIT_CLUB,
        SUIT_DIAMOND,
        SUIT_HEART,
        SUIT_SPADE,

        MAX_SUITS
    };

private:
    Rank m_rank{};
    Suit m_suit{};

public:
    Card(const Rank &rank = Rank::RANK_ACE, const Suit &suit = Suit::SUIT_SPADE);
    char rank() const;
    int value() const;
    void print() const;
    char suit() const;
    bool isAce() const;
};

#endif // CARD_H
