/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#ifndef CARDPILE_H
#define CARDPILE_H
#include<iostream>
#include<ctime>
#include<random>
#include<cstdlib>
#include "Card.h"

class CardPile{
   
protected:
    vector<Card> pile; 
public:
    CardPile();
    void add(Card c1);
    void remove(); 
    void shufflePile();
    bool isEmpty();
    
};




#endif