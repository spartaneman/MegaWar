/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#include <iostream>
#include "Deck.h"

using namespace std;
char Suits[] = {'s','h','d','c'};
char Ranks[] = {'a','2','3','4','5','6','7','8','9','t','j','q','k'};

//constructs basic 52 card deck
Deck::Deck()
{
    for(char su: Suits)
    {
        for(char ra: Ranks)
        {
            Card c(ra, su);
            add(c); 
        }
    }
}

//clears the deck and refills it
void Deck::refreshDeck()
{
    this->pile.clear();
    for(char su: Suits)
    {
        for(char ra: Ranks)
        {
            Card c(ra, su);
            add(c); 
        }
    }
}
/*
gets the last card and then removes it
@return temp: card at the top of the deck
*/
Card Deck::deal()
{
    Card temp = pile.back();
    pile.pop_back();
    return temp; 
}

/*
shuffles deck
*/
void Deck::shuffleDeck()
{
    shufflePile();
}
//debug purposes 
void Deck::display()
{
    for(auto i: this->pile)
    {
        cout<< i;
    }
    cout<<this->pile.size()<<endl;
}

