/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#ifndef MEGADECK_H
#define MEGADECK_H

#include<iostream>
#include "Deck.h"
#include "CardPile.h"

class MegaDeck: public CardPile
{
private:
    int decks;
public:
    MegaDeck();
    MegaDeck(int d);
    Card deal();
    void shuffleDeck();
};

#endif