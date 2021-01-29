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
#ifndef SHIP_H
#define SHIP_H

#include <stdexcept>
#include <string>
#include <vector>
#include "Point.h"
#include "Board.h"

/**
Vertical means top to bottom and Horizontal means left to right
*/
enum Direction { VERTICAL, HORIZONTAL };

/**
Template to use unsigned int throughout the class.
*/
template<unsigned px = 10, unsigned py = 10>

/**
Represents each individual Ship on the board and all the information
pertaining to the Ships.
*/
class Ship {

private:

	/**
	Name of the ship
	*/
	std::string name;

	/**
	The co-ordinates of the ship
	*/
	std::vector <Point<px, py>*> ship;

public:

	/**
	Parameterized constructor that sets the private data member variables
	to the arugments.

	@param std::string name: Name of the ship.
	@param const std::vector<Point<px, py>*> ship: All the points of the ship.
	*/
	Ship(std::string name, const std::vector<Point<px, py>*> ship) : name(name), ship(ship) {}

	/**
	Similar to the constructor above, just a different method of getting the vector of Point pointers.
	Checks to make sure each point that the ship will be placed on isn't already taken.

	@param std::string name: Name of the Ship.
	@param const Point<px, py>& point: Starting point of the ship.
	@param unsigned len: length of the ship.
	@param Direction direction: which direction the ship is going.
	@param Board<px, py>& board: all the points on the board.

	@throw std::invalid_argument e: If a ship already occupies a point we are checking, then this is thrown.
	@throw std::out_of_range e: If a ship point is out of bounds of the board, then throw this error.
	*/
	Ship(std::string name, const Point<px, py>& point, unsigned len, Direction direction, Board<px, py>& board) : name(name) {
		std::vector<Point<px, py>*> newShip;
		try {
			for(unsigned i = 0; i < len; i++) {
				if(direction == VERTICAL)
					newShip.push_back(board.getShipPoint(point, 0, i));	
				else
					newShip.push_back(board.getShipPoint(point, i, 0));
			}
			ship = newShip;
		} catch(...) {
			for(auto currPoint : newShip)
				currPoint->status = EMPTY;
			throw;
		}
	}

	/**
	Setter function to set the name of the ship.
	
	@param std::string n: New name for the ship.
	*/
	void setName(std::string n) {
		name = n;
	}

	/**
	Getter function to retreieve the name of the ship.

	@return std::string: The name of the ship.
	*/
	std::string getName() {
		return name;
	}

	/**
	Checks to see if a point on the board contains a ship that has been hit.

	@param const Point<px, py>& point: Point on the board
	
	@return bool: true if it has been hit, false otherwise.
	*/
	bool isHit(const Point<px, py>& point) const;

	/**
	Checks to see if a ship has been sunk by loop through all of a 
	ship's points and seeing if the status of all the points is a HIT.
	If it is it is sunk, if not it is still afloat.
	
	@return bool: true is all points in a ship have a HIT status, false otherwise.
	*/
	bool isSunk() const {
		for(auto point : ship) {
			if(point->status != HIT)
				return false;
		}
		return true;
	}
};

template<unsigned px, unsigned py>
bool Ship<px, py>::isHit(const Point<px, py>& point) const {
	for(auto newPoint : ship) {
		if(newPoint->x == point.x && newPoint->y == point.y) {
			newPoint->status = HIT;
			return true;
		}
	}
	return false;
}

#endif
