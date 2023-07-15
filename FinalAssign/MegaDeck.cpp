/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#include "MegaDeck.h"

using namespace std;

/*
basic constructor makes one deck mega deck 
*/
MegaDeck::MegaDeck()
{
    Deck deck;
    for(int i = 0; i<52; i++)
    {
        add(deck.deal());
    } 
}
/*
@param d : number of decks to include in mega deck
*/
MegaDeck::MegaDeck(int d)
{
    Deck deck;
    for(int i = 1 ; i<= d; i++)
    {
        for(int i =0; i<52; i++)
        {
            add(deck.deal());
        }
        deck.refreshDeck();
    }
}

/*
@return temp : card at end of pile
*/
Card MegaDeck::deal()
{
    Card temp = this->pile.back();
    this->pile.pop_back();
    return temp; 
}

//shuffles deck
void MegaDeck::shuffleDeck()
{
    shufflePile();
}
