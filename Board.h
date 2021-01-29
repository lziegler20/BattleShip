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
#ifndef BOARD_H
#define BOARD_H

#include <stdexcept>
#include <iostream>
#include "Point.h"

/**
Template to use unsigned int throughout the class.
*/
template<unsigned px = 10, unsigned py = 10>

/**
Represents the entire board of the BattleShip game.
*/
class Board {

	/**
	Produces the output of the entire board of one player.

	@param std::ostream &os: All the information at each point, whether
	there is a miss or hit there or a ship or empty.
	@param const Board<px, py> &b: Board containing all the points for the game

	@return std::ostream&: The stream of the board and all the points and their
	statuses.
	*/
	friend std::ostream& operator<<(std::ostream &os, const Board<px, py> &b) {
		os << "   ";
		for(unsigned x = 0; x < px; x++)
			os << Point<px, py>::xToChar(x);
		os << std::endl;
		for(unsigned i = 0; i < py; i++) { 
			if((i + 1) > 99)
				os << i + 1;
			else if((i + 1) > 9)
				os << " " << i + 1;
			else
				os << "  " << i + 1;
			for(unsigned j = 0; j < px; j++) {
				if(b.board[j][i].getStatus() == SHIP && !b.hideShips)
					os << "=";
				else if(b.board[j][i].getStatus() == HIT)
					os << "*";
				else if(b.board[j][i].getStatus() == MISS)
					os << "x";
				else
					os << "~";	
			}
			os << std::endl;
		}
		return os;
	}

private:

	/**
	2D representation of the board, updates as the game progresses
	*/
	Point<px, py> board[px][py];

	/**
	When board is displayed, ships will not be hidden, if set to false.
	*/
	bool hideShips;

public:

	/**
	Parameterized constructor that initializes the board.

	@param bool hide: true if the player wants boats hidden from the playing screen
	false if the player wants to see the ship locations on the screen.
	*/
	explicit Board(bool hide = true) : hideShips(hide) {
		for(unsigned i = 0; i < py; i++) {
			for(unsigned j = 0; j < px; j++) {
				board[i][j] = Point<px, py>(i, j);
			}
		}
	}

	/**
	Setter method that makes the given point on the board have the status of the argument.

	@param const Point<px, py> p: Point that will have it's status changed.
	@param Status s: New status to be given to the point.
	*/
	void setStatus(const Point<px, py> p, Status s) {
		board[p.x][p.y].status = s;
	}

	/**
	Sets a pointer to a Point on the board and checks in that point doesn't contain any
	ships.

	@param const Point<px, py> &p: Point to be used for it's x and y co-ordinates to find
	a new point, or use the original point.
	@param unsigned X: X offset if the ship has HORIZONTAL direction.
	@param unsigned Y: Y offset if the ship has VERTICAL direction.

	@throw std::invalid_argument: If a ship already occupies a point we are checking, then this is thrown.

	@return Point<px, py>*: pointer pointing to a point that the ship is able to succesffully
	be placed into.
	*/
	Point<px, py>* getShipPoint(const Point<px, py> &p, unsigned X, unsigned Y);
};

template<unsigned px, unsigned py>
Point<px, py>* Board<px, py>::getShipPoint(const Point<px, py> &p, unsigned X, unsigned Y) {
	Point<px, py>* ptr = &board[p.x + X][p.y + Y];
	if(ptr->status == SHIP)
		throw std::invalid_argument("Oops, there is a ship there already!");
	if((p.x + X) > 9 || (p.x + X) < 0) {
		throw std::out_of_range("Oops, that ship would be out-of-bounds!");
	}
	if((p.y + Y) > 9 || (p.y + Y) < 0) {
		throw std::out_of_range("Oops, that ship would be out-of-bounds!");
	}
	setStatus(board[p.x + X][p.y + Y], SHIP);
	return ptr;
}

#endif