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
#include <iomanip>
#include "Card.h"
#include "MegaDeck.h"
#include "WarPile.h"
#include "LostFoundPile.h"
#include "Player.h"
using namespace std;
enum states{dead=0, alive, war};

//Alive Players give one card to war pile and check highest card value
struct battle{
  int highest; 
  int count; 
};

/*
Adds card from all alive player into the War pile 
sets player state to dead if they run out of cards
@param players: vector of players
@param warPile: Vector of players to add card to 
*/
void addCardAlive(vector<Player>& players, WarPile& warPile)
{
  vector<Player>::iterator it; 
  for(it = players.begin(); it!= players.end(); it++)
  {
    if((*it).getState()== alive)
    {
      if(!(*it).isEmpty())
      {
        Card temp = (*it).giveCard();
        warPile.addCard(temp);
      }
      //if it did deplete players card pile then set players state to dead
      else
      {
        (*it).setState(dead);
      }
    }
    else
    {
      continue;
    }
  }
}
/*
this is to add cards to 
*/
void addCardWar(vector<Player>& players, WarPile& warPile)
{
  vector<Player>::iterator it; 
  for(it = players.begin(); it!= players.end(); it++)
  {
    if((*it).getState()== war)
    {
      if(!(*it).isEmpty())
      {
        Card temp = (*it).giveCard();
        warPile.addCard(temp);
      }
      //if it did deplete players card pile then set players state to dead
      else
      {
        (*it).setState(dead);
      }
    }
    else
    {
      continue;
    }
  }
}
/*
returns value of highest card from all participating players
@param players: vector of players
@param warPile: Warpile
@param state: state of battle, normal or war
*/
int getHighest(vector<Player>& players, WarPile& warPile, states state)
{
  int highestCard = 0; 
  vector<Player>::iterator it; 
  for(it = players.begin(); it!= players.end(); it++)
  {
    //if state is alive
    if(state == alive)
    {

      if((*it).getState()==alive)
      {
      //check that previous battle did'nt deplete players pile
        Card temp = (*it).getTop();
        (*it).battlesIn();
        if(temp.getRank()>highestCard)
        {
          highestCard = temp.getRank();
        }
      }
    }
    //else it equals to war
    else
    {
      if((*it).getState()== war)
      {
        Card temp = (*it).getTop();
        (*it).battlesIn();
        if(temp.getRank()>highestCard)
        {
          highestCard = temp.getRank();
        }
      }
    }    
  }
  return highestCard;
}

  /*New Method: Start of initial battle*/
//Check that there are more than one player
/*
Checks whether there are anyplayers left in the game
@param plyrs: vector of player objects
*/
bool contPlay(vector<Player>& plyrs){
  vector<Player>::iterator it;
  int count=0;
  for(it = plyrs.begin(); it!= plyrs.end(); it++)
  {
    //get count of players still alive 
    if((*it).getState()==alive)
    {

      count++; 
    }
    //makes sure that player is dead if empty pile
    if((*it).isEmpty())
    {
      (*it).setState(dead);
    }
  } 
  //game ends when one player remains or no players remain
  return count>1; 
}
/*
Deals all cards in mega deck to players
@param numPlay: number of players
@param players: vector of player objects
@param gameDeck: MegaDeck
*/
void dealCards(int numPlay, vector<Player>& players, MegaDeck& gameDeck)
{
  while(!gameDeck.isEmpty())
  {
    for(int j =0; j<numPlay; j++)
    {
      if(gameDeck.isEmpty())
      {
        break;
      }
      else
      {
        Card temp = gameDeck.deal();
        players[j].addCard(temp);
      }
    }
  }
}
/*
give winner of battle or war the spoils of the warpile and lostPile if war won
@param players: vector of players
@param warPile: 
@param lostpile:
@param state: alive or war
*/
void spoilsOne(vector<Player>& players, WarPile& warPile, LostFoundPile& lostPile, states state)
{
  //player with highest card gets all cards in warpile
    vector<Player>::iterator it;
    for(it = players.begin(); it!= players.end(); it++)
    {
      //check state
      if((*it).getState()==war)
      {           //give winner all cards from warpile and lost and found pile
        while(!warPile.isEmpty())
        {
          (*it).addCard(warPile.giveCard());
        }
        if(state == war)
        {
          if(!lostPile.isEmpty())
          {
            while(!lostPile.isEmpty())
            {
              (*it).addCard(lostPile.removeCard());
            }
          }
        }
        
        (*it).setState(alive);
        (*it).battlesWon();
      }
    }
}

/*
checks to see if all players in war have lost all their cards
@param players: vector of players
@return inWar==0
*/
bool lostAll(vector<Player> players)
{
  vector<Player>::iterator iter;
  int inWar=0;
  for(iter= players.begin(); iter!=players.end(); iter++)
  {
    if((*iter).getState()==war)
    {
      inWar++;
    }
  }
  return inWar==0;
}
/*
Main game
@param p: number of players
@param d: number of decks
*/
void game(int p, int d)
{
  //objects
  vector<Player> players;
  int numPlay = p;
  int numDecks =d;
  int battles = 0;
  bool conPlay = true;
  WarPile warPile;
  int warCount=0;   
  LostFoundPile lostPile; 

  //create vector of players
  for(int i = 0; i < numPlay; i++)
  {
    Player player;
    players.push_back(player);
  }
  //create MegaDeck
  //deal cards to all players
  MegaDeck gameDeck(numDecks);
  gameDeck.shuffleDeck();
  dealCards(p,players, gameDeck);
  while(conPlay)
  {
    //get highest value
    addCardAlive(players, warPile);
    int highest = getHighest(players, warPile, alive);
    vector<Player>::iterator it; 
    int highCount=0;
    //check which cards have highest value 
    for(it = players.begin(); it != players.end(); it++)
    {
      if(!(*it).isEmpty())
      {
         if((*it).getTop().getRank()==highest)
        {
          //if value equal then set it to war
          (*it).setState(war);
          highCount++;
        }
      }
     
      else
      {
        continue; 
      }
    }

    //if only one player has high card
    if(highCount == 1)
    {
      spoilsOne(players, warPile, lostPile, alive); 
      conPlay = contPlay(players);
      battles++;
    } 
    else
    {
      //everyplayer with war state adds 4 additional cards to pile
      while(highCount>1)
      {
        highCount =0;
        for(int i =0; i<4; i++)
        {
          //players give four card to the war pile 
          //cards go into dead state if they run out during first 3 removes
          //player with empty pile but still with one last top card 
          //gets a chance to win. 
          addCardWar(players, warPile);
        }
        //check the top
        highest = getHighest(players, warPile, war);
        for(it = players.begin(); it != players.end(); it++)
        {
          //check all players that are still active for war
          if((*it).getState()==war)
          {
            
            
            if((*it).getTop().getRank()==highest)
            {
              
              
                //if value equal then set it to war
                (*it).setState(war);
                highCount++;
            }
            else
            {
              (*it).setState(alive);
              if((*it).isEmpty())
              {
                (*it).setState(dead);
              }
            }
            }  
          }
          if(highCount == 1)
          {
            spoilsOne(players, warPile, lostPile, war); 
            battles++;
            highCount=0;
          }
          else if(lostAll(players))
          {
            while(!warPile.isEmpty())
            {
              lostPile.addCard(warPile.giveCard());
            }
            break;
          }
          else
          {
            highCount=3; 
            battles++;
          }
          
      }
      conPlay = contPlay(players);
    }
    //calculate FIERCENESS
    //display battle results
    vector<Player>::iterator iter;
    cout<<"Battle "<<battles<<" Stats:"<<endl; 
    int index = 1;
    for(iter= players.begin(); iter!=players.end(); iter++)
    {
      (*iter).setFierce();
      cout<<"Player "<<index<<": "<<(*iter);
      index++;
    }
    cout<<endl;
  }
  vector<Player>::iterator iter;
  int winner=1;
  for(iter= players.begin(); iter!=players.end(); iter++)
  {
    if(!(*iter).isEmpty())
    {
      cout<<"Congratulations Player "<<winner<< " You Won the War!!!"<<endl;
    }
    winner++;
  }
    
}

int main()
{
	cout<<"  WELCOME TO MEGA WAR"<<endl;
  cout<<"________________________"<<endl;

  cout<<"\nSimulate card game on user input"<<endl;
  cout<<"Please enter number of Players>> "<<endl;
  cout<<"Please enter number of Decks to use>> "<<endl;
  cout<<"Simulating 5 players and 3 decks"<<endl;
  int players = 5;
  int decks = 3;

  game(players, decks);
  
	return 0;
}