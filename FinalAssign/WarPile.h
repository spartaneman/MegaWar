/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#ifndef WARPILE_H
#define WARPILE_H
#include <iostream>
#include "Pile.h"
#include "Card.h"


class WarPile: public Pile<Card>
{
public:
  WarPile();
  Card giveCard();
  void addCard(Card c1);
  
};
#endif