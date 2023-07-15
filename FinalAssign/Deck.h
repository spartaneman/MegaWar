/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#ifndef DECK_H
#define DECK_H

#include <iostream>

#include "CardPile.h"


using namespace std;


class Deck: public CardPile
{
public:
    Deck();
    void refreshDeck();
    Card deal();
    void shuffleDeck();
    void display();
    
};

#endif