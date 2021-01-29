# README for Assignment 7
## Author: Logan Ziegler
## Email: lziegler3@wisc.edu
## Student ID: 9074879082

## Description 
Point.h creates points that will be placed in the board. Board.h creates the board
of points and will contain ships once they are place on them. Ship.h creates the ships
and contains information about the each ship, whether it is vertical or not, sunk or not,
hit or not, length, and name. BattleShip.cpp is more of the gameplay and what happens based
on user input that will lead to the calling of the other 3 header files functions.
BattleShip.h mostly contains just declarations that are defined in BattleShip.cpp.

## Organizaiton of Code
BattleShip.cpp contains the main() function and all the other functions declared in
BattleShip.h which call all the functions within the 4 header files and uses them
as accordingly towards the gameplay. All the function declarations and definitions, 
the member declarations, and include guards are all within Point.h, Ship.h, Board.h,
and BattleShip.h. BattleShip.cpp contains include guards also.

## Compile/Run
To compile the program on Linux computers, go into the file that 
contains all the work and simply type the command: make. This compiles the program 
and creates an executable named BattleShipdemo which allows the program to run.
The executable: BattleShipdemo will run the program and goes through BattleShip.cpp
which can call all the functions in the 4 header files. The command: make clean
cleans the directory of the executable and object files.