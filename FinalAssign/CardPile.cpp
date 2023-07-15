/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#include<iostream>
#include<string>
#include<vector>
#include "Card.h"
#include "CardPile.h"

using namespace std;

CardPile::CardPile()
{

}
/*
add card to pile
@param c1
*/
void CardPile::add(Card c1)
{
    Card temp = c1;
    pile.push_back(temp);
}

/*
Remove card from end of pile
*/
void CardPile::remove()
{
   pile.pop_back();
}

/*
Shuffles the pile
*/
void CardPile::shufflePile()
{
    srand(time(NULL));
    for(int r = 0; r < 100000; r++ )
    {
        int val = rand()%pile.size();
        int next = rand()%pile.size();
        
        Card temp = pile[val];
        pile[val] = pile[next];
        pile[next] = temp; 
    }
}

/*
@return whether the pile is empty
*/
bool CardPile::isEmpty()
{
    return pile.empty();
}