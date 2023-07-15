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
#include "WarPile.h"

WarPile::WarPile()
{
  
}
/*
*removes card from war pile and returns card
*@param temp: returns Card object
*/
Card WarPile::giveCard()
{
  Card temp = this->pile.back();
  this->pile.pop_back();
  return temp; 
}
/*
*Add card to pile
*@param c1: Card to add to pile
*/
void WarPile::addCard(Card c1)
{
   add(c1);
}



