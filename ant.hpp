/***************************************************************
** Author: Theresa Phan
** Date: July 06, 2019
** Description: This is the header file for the class Ant.
***************************************************************/
#ifndef ANT_HPP
#define ANT_HPP

class Ant
{
    private:
        //X position of ant
        int antX;
        //Y position of ant
        int antY;
        //Orientation of ant
        char direction;

    public:
        //Ant constructor
        Ant(int, int, char);

        //Ant Methods

        //Getter Methods
        int getX();
        int getY();
        char getDirection();

        //Setter Methods
        void setX(int);
        void setY(int);
        void setDirection(char);

        //Moves ant forward a step
        void move();
        //Rotates ant clockwise
        void rotateCW();
        //Rotates ant counter-clockwise
        void rotateCCW();
        //Checks whether ant is at the border of the board
        void checkBorder(int, int);

};
#endif