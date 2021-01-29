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
#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <stdexcept>

/**
Forward declaration to allow Board to be a friend of Point.
*/
template<unsigned px, unsigned py> class Board;

/**
Forward declaration to allow Ship to be a friend of Point.
*/
template<unsigned px, unsigned py> class Ship;

/**
Enumeration containing the status of a specific point being that
it is empty or contains a ship and if the oppenent has hit or missed
this at this point.
*/
enum Status { EMPTY, SHIP, MISS, HIT };

/**
Template to use unsigned int throughout the class.
*/
template<unsigned px = 10, unsigned py = 10>

/**
Class that refers to each individual point on the board for this game.
*/
class Point {

	/**
	Allows Board to access private members within Point.
	*/
	friend class Board<px, py>;

	/**
	Allows Ship to access private members within Point.
	*/
	friend class Ship<px, py>;

	/**
	Comparing 2 Points to see if they are the same.

	@param const Point &a: Point being compared using it's x and y co-ordinates.
	@param const Point &b: Point being compared using it's x and y co-ordinates.

	@return bool: true if both the first point's x and y equal the
	second point's x and y respectively, false otherwise.
	*/
	friend bool operator==(const Point<px, py> &a, const Point<px, py> &b) {
		if(b.x == a.x && b.y == a.y)
			return true;
		return false;
	}

	/**
	Produces the output of a single point.

	@param std::ostream &os: All the information of the point, parentheses, and
	comma are stored in this stream.
	@param const Point &p: The point that will be put to the output.

	@return std::ostream&: The stream of parentheses, the point and a comma.
	*/
	friend std::ostream& operator<<(std::ostream &os, const Point<px, py> &p) {
        os << "(" << (p.y + 1) << "," << Point<px, py>::xToChar(p.x) << ")";
    	return os;
	}

private:

	/**
	x co-ordinate on the board
	*/
	unsigned x;

	/**
	y co-ordinate on the board
	*/
	unsigned y;

	/**
	Status of a given point on the board
	*/
	Status status;

public:

	/**
	Default constructor
	*/
	Point() = default;

	/**
	Setting the co-ordinates of a new point.

	@param char c: Letter that states what column the point is in.
	@param unsigned y: Int stating what row the point is in.

	@throw std::out_of_range e: If a ship point is out of bounds of the board, then throw this error.
	*/
	Point(char c, unsigned y) {
		if(y > 9 || y < 0)
			throw std::out_of_range("Oops, that ship would be out-of-bounds!");
		unsigned newX = xToInt(c);
		if(newX > 9 || newX < 0)
			throw std::out_of_range("Oops, that ship would be out-of-bounds!");
		this->y = y;
		this->x = newX;
	}

	/**
	Setting the co-ordinates of a new point.

	@param unsigned x: Int that states what column the point is in.
	@param unsigned y: Int stating what row the point is in.

	@throw std::out_of_range e: If a ship point is out of bounds of the board, then throw this error.
	*/
	Point(unsigned x, unsigned y) {
		if(x > 9 || x < 0) {
			throw std::out_of_range("Oops, that ship would be out-of-bounds!");
		}
		if(y > 9 || y < 0) {
			throw std::out_of_range("Oops, that ship would be out-of-bounds!");
		}
		this->x = x;
		this->y = y;
	}

	/**
	Makes the y co-ordinate into a char.

	@param unsigned num: co-ordinate converted into a column char.

	@return char: letter representing a column on the board.
	*/
	static char xToChar(unsigned num) {
		return static_cast<char>(num + 'A');
	}

	/**
	Makes a char point into a num.

	@param char c: point converted into a num co-ordinate.

	@return unsigned: point representing the y variable.
	*/
	static unsigned xToInt(char c) {
		return static_cast<unsigned>(c - 'A');
	}

	/**
	Getter method to return the status of the current point.

	@return Status: The status of the point.
	*/
	Status getStatus() const {
		return status;
	}

};

#endif