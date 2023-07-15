/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#ifndef CARD_H
#define CARD_H
#include <iostream>
using namespace std;
class Card
{
    private:
    enum eRanks{failr= 0, ace = 1, two, three, four, five, six, seven, eight, nine, ten , jack , queen, king};
    enum eSuits{fails= 0, spade=1, heart, diamond, club};
    int rank; 
    int suit;
    int ranks(char r);
    int suits(char s);
     
    public: 
    Card();
    Card(const Card& c1);
    Card(char s, char r);
    void setCard(char s, char r);
    int getRank();
    int getSuit();
    bool operator<(Card& c1);
    bool operator==(Card& c1);
    bool operator<=(Card& c1);
    Card& operator=(Card& c1);
    void swap(Card& a, Card& b);
    friend ostream& operator<<(ostream& out, Card c );
};

#endif