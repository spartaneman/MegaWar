/*
 * Emanuel Ruiz 
 * CECS 282-01
 * Program # 6 - Mega War: Inheritance
 * due date: Dec 12, 2021
 * 
 * I certify that this program is my own original work. I did not copy any part of this program from any other 
 * source. I further certify that  I typed each and every line of code in this program. 
 * */

#ifndef PILE_H
#define PILE_H
#include <iostream>
#include <vector>
#include <ctime>
#include <random>


template<typename T>
class Pile{
    protected:
        std::vector<T> pile;
    public:
        Pile();
        void add(T c);
        void remove();
        void shufflePile();
        bool isEmpty();
};

template<typename T>
Pile<T>::Pile(){

}

template<typename T>
void Pile<T>::add(T c1){
    T temp = c1;
    pile.push_back(temp);
}

template<typename T>
void Pile<T>::remove(){
    pile.pop_back();
}

template<typename T>
void Pile<T>::shufflePile(){
    srand(time(NULL));
    for(int r = 0; r < 10000; r++)
    {
        int val = rand()%pile.size();
        int next = rand()%pile.size();

        T temp = pile[val];
        pile[val] = pile[next];
        pile[next] = temp;
    }
}

template<typename T>
bool Pile<T>::isEmpty(){
    return pile.empty();
}

#endif