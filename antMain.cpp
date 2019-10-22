/**************************************************************************************
** Author: Theresa Phan
** Date: July 06, 2019
** Description: This is the main file for the Langton's Ant simulation. This file 
** contains the menu function that first prompts the user to enter a number 1 or 2. If 
** the user enters the number 1, the simulation will begin. Otherwise, the program will 
** quit. This file also contains a function to print the board. 
**************************************************************************************/

#include "ant.hpp"
#include<iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// Menu function that prints menu options to the screen for the user, prompts the user for the inputs,
// verify the user's inputs, and return the value back to the program. 
void menu(int *rowNum, int *columnNum, int *stepNum, int *row, int *column, char *orientation, bool *flag){

    int selection;
    bool selectionFlag = true;

    cout << "Welcome to the Langton's Ant simulation!" << endl;

    while(selectionFlag){
        cout << "Enter the number 1 or 2 for your selection." << endl;
        cout << "1: Start user generated Langton's Ant simulation" << endl;
        cout << "2: Quit" << endl;
        cin >> selection;

        if(selection == 1){

            //Gets the rows of the board.
            cout << "Size of the board:" << endl;
            cout << "Enter a positive integer from 1 to 100 for the number of rows." << endl;
            cin >> *rowNum;

            //User enters a negative number
            while(*rowNum < 1 || *rowNum > 100){
                cout << "The number of rows must be an integer from 1 to 100. Please try again." << endl;
                cin.clear();
                cin.ignore();
                cin >> *rowNum;
            }

            //Gets the columns of the board.
            cout << "Enter a positive integer from 1 to 100 for the number of columns." << endl;
            cin >> *columnNum;

            while(*columnNum < 1 || *columnNum > 100){
                cout << "The number of columns must be an integer from 1 to 100. Please try again." << endl;
                cin.clear();
                cin.ignore();
                cin >> *columnNum;
            }
            //Gets the steps from the user. 
            cout << "Number of steps: " << endl;
            cout << "Enter a positive integer that is below 15,000 for the number of steps you want the ant to take." << endl;
            cin >> *stepNum;

            // Limits the step number to less than 15,000 steps so the program doesn't crash if the user puts a 
            // that is greater than 15,000. 
            while(*stepNum < 0 || *stepNum > 15000){
                cout << "The number of steps must be a positive integer and below 15,000. Please try again." << endl;
                cin.clear();
                cin.ignore();
                cin >> *stepNum;
                }
            
            char randLocation;
            bool flag2 = true;

            while(flag2){
                //Asks the user if he or she would like the ant to start at a random location for extra credit. 
                cout << "Enter the letter 'Y' if you would like the ant to start at a random location for EXTRA CREDIT. Otherwise, enter the letter 'N'." << endl;
                cin >> randLocation;

                //User enters 'y' or 'Y'. This will generate random row/column numbers.
                if(randLocation == 'y' || randLocation == 'Y'){
                    srand(time(NULL)); //Initializes random seed to get a different set of random numbers each time. Reference: http://www.cplusplus.com/reference/cstdlib/rand/
                    
                    //Generates a random number in the range of input row and column.
                    *row = rand() % *rowNum; 
                    *column = rand() % *columnNum;
                    flag2 = false;
                }
                //User enters 'n' or 'N'. This will generate the rows and columns based on the input of the user. 
                else if (randLocation == 'n' || randLocation =='N'){
                    cout << "Enter an integer for the row number (starting at row 1) of the ant's starting position." << endl;
                    cin >> *row;
                    while(*row < 0 || *row > *rowNum){
                        cout << "The Ant's starting position X must be within the board's range. Please try again" << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> *row;
                    }
                    cout << "Enter an integer for the column number (starting at column 1) of the ant's starting position." << endl;
                    cin >> *column;
                    while(*column < 0 || *column > *columnNum){
                        cout << "The Ant's starting position Y must be within the board's range. Please try again" << endl;
                        cin.clear();
                        cin.ignore();
                        cin >> *column;
                    }
                    flag2 = false;
                }else{
                    cout << "The selection must be 'y' or 'n'. Please try again" << endl;
                }
            }

            bool flag3 = true;
            while(flag3){
                //Prompts the user to enter the orientation of the ant. 
                cout << "Enter the starting orientation for the ant." << endl;
                cout << "Enter 'n' for north, 'e' for east, 's' for south, 'w' for west" << endl;
                cin >> *orientation;

                switch(*orientation){
                    case 'n': flag3 = false;
                            break;
                    case 'e': flag3 = false;
                            break;
                    case 's': flag3 = false;
                            break;
                    case 'w': flag3 = false;
                            break;
                    default: cout << "Invalid input. Please try again";
                            cin.clear();
                            cin.ignore();
                }
            }
            selectionFlag = false;
        }else if(selection == 2){
            selectionFlag = false;
            *flag = false;
        }else{
            cout << "Invalid selection. Please select 1 or 2. \n" << endl;
            cin.clear();
            cin.ignore();
        }

    }
}

//Function to print board state
void printBoard(char **board, int row, int col, Ant antSim){
    string str = "";
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == antSim.getX() && j == antSim.getY()){
                str += "* ";
            }else{
                str += board[i][j];
                str += ' ';
            }
        }
        str += "\n";
    }
    cout << str;
}

int main(){ 

    //Initializes variables
    int rowNum, columnNum, row, column, stepNum;
    char orientation;
    bool flag = true;

    while(flag){

        menu(&rowNum, &columnNum, &stepNum, &row, &column, &orientation, &flag);

        if(flag){
            //Creates and dynamically allocates the board.
            char **board = new char*[rowNum];
            for(int i = 0; i < rowNum; i++){
                board[i] = new char[columnNum];
            }

            //Initializes the board with blank spaces to respresent the white tiles (space character). 
            for(int i = 0; i < rowNum; i++){
                for(int j = 0; j < columnNum; j++){
                    board[i][j] = ' ';
                }
            }

            //Creates the Ant for the simulation
            Ant antSim(row-1, column-1, orientation);

            //For loop for how many times the ant takes a step
            for(int i = 0; i < stepNum; i++){
                //Space ant is moving from is white, and turns it black. Ant rotates counter-clockwise.
                if( board[antSim.getX()][antSim.getY()] == ' '){
                    board[antSim.getX()][antSim.getY()] = '#';
                    antSim.rotateCCW();
                //Space ant is moving from is black, and turns it white. Ant rotates clockwise.
                }else{
                    board[antSim.getX()][antSim.getY()] = ' ';
                    antSim.rotateCW();
                }

                //If Ant attempts to move out of bounds, antSim.checkBorder() rotates the ant 180 degrees before taking a step forward
                antSim.checkBorder(rowNum-1, columnNum-1);

                //Moves the ant forward
                antSim.move();

                //Prints board state
                printBoard(board, rowNum, columnNum, antSim);

                //This is to test the output of the ant in the for loop. 
                // cout << endl;
                // cout << "Number of Step: " << i+1 << ", X position: " << antSim.getX() << ", Y position: " << antSim.getY() << ", Direction: " << antSim.getDirection() << ", Board State: " << board[antSim.getX()][antSim.getY()] << endl;
            }

            //Deleting dynamically allocated array
            for(int i = 0; i < columnNum; i++){
                delete[] board[i];
            }
            delete[] board;
        }
    }
    return 0;
}
