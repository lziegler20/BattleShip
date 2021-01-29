//////////////////// ALL ASSIGNMENTS INCLUDE THIS SECTION /////////////////////
//
// Title: Assignment 7
// Files: BattleShip.h, BattleShip.cpp, Point.h, Ship.h, Board.h, Makefile, README.md
// Course: CS 368, Spring 2020
//
// Author: Logan Ziegler
// Email: lziegler3@wisc.edu
// Student ID: 9074879082
// Lecturer's Name: Marc Renault
//
//////////////////// Library Description //////////////////////////////////////
//
// Header file that contains all the include guards and method declarations and
// definitions used in BattleShip.cpp.
//
///////////////////////////// CREDIT OUTSIDE HELP /////////////////////////////
//
// Students who get help from sources other than their partner must fully
// acknowledge and credit those sources of help here. Instructors and TAs do
// not need to be credited here, but tutors, friends, relatives, room mates,
// strangers, and others do. If you received no outside help from either type
// of source, then please explicitly indicate NONE.
//
// Persons: None.
// Online Sources: None.
//
/////////////////////////////// 80 COLUMNS WIDE ///////////////////////////////
#ifndef BATTLESHIP_MAIN_H
#define BATTLESHIP_MAIN_H

#include <random>
#include <vector>
#include "Point.h"
#include "Ship.h"
#include "Board.h"

/**
The variables used for the template values throughout the classes.
*/
constexpr unsigned MAX_X{10};
constexpr unsigned MAX_Y{10};

/**
Player's ships being initialized.
*/
std::vector<Ship<MAX_X,MAX_Y>> player;

/**
Computer's ships being initialized.
*/
std::vector<Ship<MAX_X,MAX_Y>> computer;

/**
Player's board being initialized.
*/
Board<MAX_X,MAX_Y> pBoard(false);

/**
Computer's board being initialized.
*/
Board<MAX_X,MAX_Y> cBoard(true);

/**
Struct defining each ship to have a length and a name.
*/
struct DefShip {
  unsigned len;
  std::string name;
};

/**
Vector containing all the lengths and names of all of the ships.
*/
std::vector<DefShip> ships {{2, "destroyer"},
                            {3, "cruiser"},
                            {3, "submarine"},
                            {4, "battleship"},
                            {5, "carrier"}};

/**
Initializes the board to start the game.
*/
void initGame();

/**
Randomly inserts the Computer's ships throughout the board, then asks the 
user where they would like to put their ships. Throws exceptions if the input 
is out of range, invalid, or going to be placed on another ship, then
asks the user again for input.

@param std::default_random_engine &rand: random device used to randomized the
computers ship locations on the board.
*/
void placeShips(std::default_random_engine &rand);

/**
Randomly selects the Computer's ships shot on the board, then asks the 
user where they would like to shoot. Throws exceptions if the input is 
out of range, invalid, then asks the user again for input. 

@param std::default_random_engine &rand: random device used to randomized the
computers ship shots on the board.
*/
void playGame(std::default_random_engine &rand);

/**
Loops through a player's ships to see if each one is sunk.

@param std::vector<Ship<MAX_X,MAX_Y>> &ships: vector containing all the
ships to be looped throguh and checked if they are all sunk.

@return bool: true if all ships are sunk, false otherwise.
*/
bool checkLost(std::vector<Ship<MAX_X,MAX_Y>> &ships);

/**
Checks, once the user has entered their desired shot destination,
whether it was a hit or miss, and if it was a hit, if it sunk a ship.
Once it has determined which of the 3 above have occured, the appropriate
message(s) relaying what happened will be printed. If a hit and a sink occur
both messages are printed, this is the only case of multiple messages being printed.

@param Point<MAX_X,MAX_Y> &shot: Co-ordinates of the user entered shot
@param std::vector<Ship<MAX_X,MAX_Y>> &ships: list of oppenent's ships to be checked.
@param Board<MAX_X,MAX_Y> &board: Used if a user misses, to update the status of that
point on the board.
*/
void doShot(Point<MAX_X,MAX_Y> &shot, std::vector<Ship<MAX_X,MAX_Y>> &ships, Board<MAX_X,MAX_Y> &board);

/**
Prints the board with all the hits, miss, non-accessed points and if hide ships is false, shows the ships.
*/
void printBoards();

#endif
