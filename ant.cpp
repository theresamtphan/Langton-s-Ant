/**************************************************************************************************** 
** Author: Theresa Phan
** Date: July 06, 2019
** Description: This is the implementation file for the Ant class. It has a constructor that takes 
** in an int that represents the x and y position of the ant as well as a character that represents 
** the direction of the ant. There are also getters and setters that return the position (x and y) and 
** direction of the ant. In addition, this file has a void function that moves the ant based on its 
** orientation, a void function that rotates the ant clockwise or counterclockwise, and another void 
** function that takes in edge cases for when the ant hits a border or corner of the board. 
*****************************************************************************************************/
#include "ant.hpp"
#include <iostream>

using namespace std;

//Constructor
Ant::Ant(int x, int y, char d){
    antX = x;
    antY = y;
    direction = d;
}

//Getter Methods
int Ant::getX(){
    return antX;
}

int Ant::getY(){
    return antY;
}

char Ant::getDirection(){
    return direction;
}

//Setter Methods
void Ant::setX(int x){
    antX = x;
}

void Ant::setY(int y){
    antY = y;
}

void Ant::setDirection(char d){
    direction = d;
}

//Changes ant's X and Y coordinate based on it's orientation (taking a step forward).
void Ant::move(){
    if(direction == 'n'){
        //ant is facing north so it will move north
        antY -= 1;
    }else if(direction == 'e'){
        //ant is facing east so it will move east
        antX += 1;
    }else if(direction == 's'){
        //ant is facing south so it will move south
        antY += 1;
    }else{
        //ant is facing west so it will move west
        antX -= 1;
    }
}

//Rotates ant 90 degrees to the right
void Ant::rotateCW(){
    if(direction == 'n'){
        direction = 'e';
    }else if(direction == 'e'){
        direction = 's';
    }else if(direction == 's'){
        direction = 'w';
    }else if(direction == 'w'){
        direction = 'n';
    }
}

//Rotates ant 90 degrees to the left
void Ant::rotateCCW(){
    if(direction == 'n'){
        direction = 'w';
    }else if(direction == 'w'){
        direction = 's';
    }else if(direction == 's'){
        direction = 'e';
    }else if(direction == 'e'){
        direction = 'n';
    }
}

//Check whether the ant is at the border and is facing the border.
//If this is the case, the ant will be rotated 180 degrees to move towards the center of the board again
void Ant::checkBorder(int rowMax, int colMax){

    //If flag is set to true, ant rotates 180 degrees
    bool flag = false;

    if(antX == 0 && direction == 'w'){
        flag = true;
    }
    if(antX == rowMax && direction == 'e'){
        flag = true;
    }
    if(antY == 0 && direction == 'n'){
        flag = true;
    }
    if(antY == colMax && direction == 's'){
        flag = true;
    }
    if(flag){
        // cout << "current dir: " << getDirection();
        rotateCCW();
        rotateCCW();
        // cout << "\nafter rotating: " << getDirection() << endl;
    }
}
