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
#include <string>
#include "Card.h"

using namespace std;
string suits[] = {"Fail", "Spades", "Hearts", "Diamond", "Club"};
Card::Card()
{
    rank = 0;
    suit = 0;
}

/*
create cards using char 
@param r: rank 
@param s: suit
*/
Card::Card(char r, char s)
{
    rank = ranks(r);
    suit = suits(s);
}

/*
copy constructor
@param c1: card to copy
*/
Card::Card(const Card& c1)
{
    rank = c1.rank;
    suit = c1.suit;
}

/*
allows to set rank and suit
@param r: rank
@param s: suit
*/
void Card::setCard(char r, char s)
{
    rank = ranks(r);
    suit = suits(s);
}

/*
set cards rank using the char and rank enum
@param r: char rank
*/
int Card::ranks(char r)
{
    int val = int(r);
    switch(val)
    {
        case 97: return eRanks::ace;
        case 50: return eRanks::two;
        case 51: return eRanks::three;
        case 52: return eRanks::four;
        case 53: return eRanks::five;
        case 54: return eRanks::six;
        case 55: return eRanks::seven;
        case 56: return eRanks::eight;
        case 57: return eRanks::nine;
        case 116: return eRanks::ten;
        case 106: return eRanks::jack;
        case 113: return eRanks::queen;
        case 107: return eRanks::king;
        default: return eRanks::failr; 
    }
}
/*
set card's suit
@param s: suit
*/
int Card::suits(char s)
{
    
    int val = int(s);
    switch(val)
    {
        case 115: return eSuits::spade;
        case 104: return eSuits::heart;
        case 100: return eSuits::diamond;
        case 99: return eSuits::club; 
        default: return eSuits::fails; 
    }
}
/*
@return rank
*/
int Card::getRank()
{
    return rank; 
}

/*@return suit*/
int Card::getSuit()
{
    return suit;
}

/*
operator override
@param c1: card to compare to
*/
bool Card::operator<(Card& c1) 
{
    return this->getRank() - c1.getRank()<0; 
}

/*
operator override
@param c1: card to compare
*/
bool Card::operator==(Card& c1) 
{
    return this->getRank()==c1.getRank();
}

/*
operator override
@param c1: card to compare
*/
bool Card::operator<=(Card& c1)
{
    if(*this < c1)
    {
        return *this < c1;
    }
    else
    {
        return *this == c1;
    }
}

/*
operator override
@param c1: card to compare
*/
Card& Card::operator=(Card& c1)
{
    this->rank = c1.getRank();
    this->suit = c1.getSuit();
    return *this;
}
//was going to be used for algorithm 
void Card::swap(Card& a, Card& b)
{
    Card c = a;
    a = b;
    b = c;
}

/*
ostream override
@param C: card to compare
*/
ostream& operator<<(ostream& out, Card c)
{
    string s = suits[c.getSuit()];
    out<<"Rank: " << c.getRank()<<" Suit: "<<s<<endl;
    return out; 
}


    