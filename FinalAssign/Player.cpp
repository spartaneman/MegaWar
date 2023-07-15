/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */
#include <iomanip>
#include "Player.h"


using namespace std;

Player::Player()
{
    battles = 0;
    fierceness=0;
    wonBattles =0;
    state=1; 
}
/*
@return temp: give top card 
*/
Card Player::giveCard()
{
    Card temp = this->pile.back();
    this->pile.pop_back();
    setTop(temp);
    return temp; 
}

/*
calculates the fierceness of everyplayer and sets fierceness
*/
void Player::setFierce()
{
  double temp;
  vector<Card>::iterator itr;
  for(itr = pile.begin(); itr !=pile.end(); itr++)
  {
    temp = temp + (*itr).getRank();
  }
  if(temp == 0.0 || pile.size()== 0.0)
  {
    fierceness =  0.0;
  }
  else
  {
    fierceness = temp/pile.size();
  }
  
}

/*
increases the number of battles the player has participated
*/
void Player::battlesIn()
{
  battles++;
}

/*
Increase the number of wins the player won
*/
void Player::battlesWon()
{
  wonBattles++;
}
/*
sets the top card, which is the card that was last given into the pile
used to check for highest card value
@param c1: 
*/
void Player::setTop(Card c1)
{
  top = c1; 
}
/*
@return top
*/
Card Player::getTop()
{
  return top;
}
/*
@param c1: card to add to pile
*/
void Player::addCard(Card c1)
{
  add(c1);
}

//debug purpose
void Player::display()
{
    for(auto i: this->pile)
    {
        cout<< i;
    }
    cout<<this->pile.size()<<endl;
}

/*
set to one of three states dead, alive, war
@param s: player state
*/
void Player::setState(int s)
{
  state= s; 
}

/*
@return state
*/
int Player::getState()
{
  return state; 
}

/*
@param out: outstream
@param p: player 
@return out: outstream
*/
ostream& operator<<(ostream& out, Player p )
{
  out<<"Fierceness = "<<setw(4)<<setprecision(3)<< p.fierceness<<setw(10)<<"Cards= "<<setw(4)
  << p.pile.size()<<setw(10)<<"Battles= " <<setw(4)<<(p.battles)<<setw(10)<<"Won= "<<p.wonBattles<<endl;
  return out;
}