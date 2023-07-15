/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#ifndef LOSTFOUNDPILE_H
#define LOSTFOUNDPILE_H
#include <iostream>
#include "CardPile.h"

class LostFoundPile: public CardPile
{
  public:
  LostFoundPile();
  void addCard(Card c1);
  Card removeCard();
  
};

#endif