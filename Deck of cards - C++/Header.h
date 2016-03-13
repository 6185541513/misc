#ifndef HEADER_H
#define HEADER_H

#include "Deck.h"
#include "Player.h"
#include <ctime>
#include <iomanip>
#include <string>
#include <iostream>
using namespace std;

string intro();
void game(Deck &deck, Player players[2]);
void round(Deck &deck, Player players[2], int &win_player, int &win_computer);
void headlineOutput();
void assignValues(Deck &deck, int valueCards[2], string presentableCards[2]);
void playersOutput(Player players[2], string cards[2]);
void winnerOutput(int cards[2], int &win_player, int &win_computer, Player players[2], Deck deck);
void presentWinner(int win_player, int win_computer, Player player[2]);
void presentUsedCards(Deck deck);
int drawCard(Deck &deck);
void keepPlaying();
void exit(Player players[2]);

#endif