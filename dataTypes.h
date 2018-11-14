//The purpose of this file is to define the structures used in this program.
//This file SHOULD NOT be used to assign values to any variables (other than the default values)
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "constants.h"
    //includes "graphicsConstants.h"

struct logicState{
    int state_number = -1;
    int action = -1;        int actionData = -1;                                    //This action occurs immediately after the individual reaches this state
    int query_A = -1;       int destination_A = -1;     int qAData = -1;             //if query or destination == -1, they should be treated as if they do not exist
    int query_B = -1;       int destination_B = -1;     int qBData = -1;
    int query_C= -1;        int destination_C = -1;     int qCData = -1;
    int destination_default = -1;
};

struct individual{  //NOTE: ALL OF THE VARIABLES DEFINED BELOW ARE DEFAULT VALUES. UNLESS YOU REDEFINE THEM FOR AN INDIVIDUAL, EVERY INDIVIDUAL WILL HAVE THESE VALUES
    int xPosition;
    int yPosition;
    int currentState = 0;
 //   logicState flowchart[10];
    int directionMoving = -1;   //-1 for not moving, then 0 for north and 7 for NW
    int energy = 250;   //default energy is 250. Cell grows in size with more energy
    bool alive = false; //alive implies exists on screen
    bool inanimate = false; //inanimate implies that it is passive. Alive && inanimate mean you've got a thing bouncing around that isnt a cell
    int divisionMinimum = 500;  //minimum energy needed for division into new cells.
 //   int cellType = CELL_red;    //Cell type is just the sprite used       DEPRECATED
    int startingState = 0;  //Starting state is number 0 by default
    int species = -1;   //species number used for picking which flowchart it uses
    int stomach[maxStomachSize];
    int stomachSize = 0;
};

struct coordinates{
    int x;
    int y;
};

struct eatingInfo{
    int energyEaten = 0;    //energy of individual that got ate
    int individualNumber = -1;  //index in "population" of the individual that got ate
};

struct soundInfo{
    int originX;
    int originY;
    int sound;
};

struct displayInfo{
    int x;
    int y;
    int cellColor;
};

//whenever the user wants to change the flowchart, a window will pop up confirming that they want to make that change.
//the window will use this structure to display the original and the new choice
//the ints will match the values for querynum and actionnum
struct confirmChangeInfo{
    int original;
    int newChoice;
};

struct mineral{
    int type;
    int directionMoving;
    int x;
    int y;
};
