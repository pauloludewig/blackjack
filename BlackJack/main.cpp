#include <iostream>
#include <string>
#include <array>
#include <numeric> // std::reduce
#include <limits>


#include "Card.h"
#include "Deck.h"
#include "Player.h"

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool getPlayerAction()
{
    char c{};
    while(c != 'h' && c != 's')
    {
        std::cout << "Hit (h) or stand(s)? ";
        std::cin >> c;
        ignoreLine();
    }

    return c == 'h';
}


bool playBlackJack()
{
    static Deck deck{};
    deck.shuffle();
    Player player{};
    Player dealer{};

    std::cout << "Dealer drew: ";
    dealer.drawCard(deck).print();
    std::cout << '\n';
    std::cout << "Dealer score: " << dealer.score() << '\n';


    while(getPlayerAction())
    {
        std::cout << "\nPlayer drew: ";
        player.drawCard(deck).print();
        std::cout << '\n';
        std::cout << "Current score: " << player.score() << '\n';
        if(player.isBusted())
        {
            std::cout << "Player busted!\n";
            return false;
        }
    }

    while(dealer.score() < 17)
    {
        std::cout << "\nDealer drew: ";
        dealer.drawCard(deck).print();
        std::cout << '\n';
        std::cout << "Current score: " << dealer.score() << '\n';
        if(dealer.isBusted())
        {
            std::cout << "Dealer busted!\n";
            return true;
        }
    }

    std::cout << "Dealer halted.\n";
    std::cout << "Player points: " << player.score() << " Dealer Points: " << dealer.score() << '\n';
    return player.score() > dealer.score();
}

int main()
{
    std::cout << "Welcome to Black Jack!\n";

    while(true)
    {
        char c{};
        while(c != 'y' && c != 'n')
        {
            std::cout << "Do you want to play? (y) or (n)? ";
            std::cin >> c;
            ignoreLine();
        }

        if(c == 'y')
        {
            if(playBlackJack())
            {
                std::cout << "You win! Congratulations!\n";
            }
            else
            {
                std::cout << "You lose!\n";
            }
        }
        else
        {
            std::cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
