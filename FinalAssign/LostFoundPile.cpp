/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#include "LostFoundPile.h"

LostFoundPile::LostFoundPile()
{
  
}

/*
@param c1 : card to add
*/
void LostFoundPile::addCard(Card c1)
{
  add(c1);
}

/*
@return temp: Card that was removed from back of pile
*/
Card LostFoundPile::removeCard()
{
  Card temp = this->pile.back();
  this->pile.pop_back();
  return temp; 
}
