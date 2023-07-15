/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "CardPile.h"


class Player: public CardPile
{
  private:
    int state; 
    Card top;
    int battles;
    int wonBattles;
    double fierceness;
  public:
    Player();
    Card giveCard();
    void setFierce();
    void battlesIn();
    void battlesWon();
    void setTop(Card c1);
    void addCard(Card c1);
    void display();
    void setState(int s);
    int getState();
    Card getTop();

    friend ostream& operator<<(ostream& out, Player p );
};
#endif