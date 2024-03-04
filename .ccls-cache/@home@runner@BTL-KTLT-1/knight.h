#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
int levelO(int i);
int s1(int n);
bool isPrime(int n);
int findPrimeNum(int n);
int fibNum(int n);
int findFibNum(int n);
int secondMaxNum(int a[], int n2);
int merlin_support(string a);
void CheckTiny_Frog(int &tinyEvent, int &frogEvent, int &HP, int &maxHP,
                    int &level, int &old_level);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

#endif // __KNIGHT_H__