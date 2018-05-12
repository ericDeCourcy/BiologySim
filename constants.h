
//This file is used to store all of the constant values used in the program
////////////////////////////////////////////////////////////////////////////////////

#include "graphicsConstants.h"

//cellTypes

const int CELL_red = 1;
const int CELL_green = 0;
const int CELL_lightBlue = 2;
//blue
//purple
//yellow
//orange
//pink
//white
//lightblue
const int CELL_grey = 20;

const int numCells = 21;

const int numQAdataOptions = 11;

//game parameters
const int numSpecies = 20;
const int numSpotsPer = 15;
const int popSize = 250;
const int mapWidth = 50;        //these are in units of spaces. 16x16 pixels per space
const int mapHeight = 40;
const int frameRatePeriod = 100; //time in ms that the game waits before stepping between each frames. Default value is 100
const int menuHeight = 100; //height of menu in pixels
const int sideMenuWidth = 112;
const int minPoints = 0;   //the minimum number of points needed to make an edit
const int errorLength = 10;

//the action codes - DONT FORGET to change numActions at the end
const int ACTION_null = -1; //if this is the first action then that individual must die
const int ACTION_born = 0;  //makes sure that the object is recorded on the gameMap
const int ACTION_goRandDir = 1; //go in a random direction (16 cardinal directions)
const int ACTION_continueMoving = 2;
const int ACTION_attemptToEat = 3;  //attempts to eat anything within range (for now, anything touching the individual)
const int ACTION_splitAndDie = 4;   //splits into as many cells as possible and dies
const int ACTION_doNothing = 5; //just like it sounds
const int ACTION_photosynth = 6;    //make one energy per time step
const int ACTION_makeNoise = 7;
const int ACTION_greyedOut = 8;     //greyedOut
const int ACTION_editSelected = 9;  //greyedOut + yellowCircle

const int numActions = 10;       //number of actions so far (1+ highest action id value)
const int numUnselectableActions = 2;

//map codes
const int   MC_emptySpace = -1;

//directions
const int   DIR_none = -1;  //no direction
const int   DIR_N = 0;      //N = north
const int   DIR_NE = 1;     //NE = north-east
const int   DIR_E = 2;      //you get the idea
const int   DIR_SE = 3;
const int   DIR_S = 4;
const int   DIR_SW = 5;
const int   DIR_W = 6;
const int   DIR_NW = 7;

//the queries
const int QUERY_moving = 0;     //is the object moving (if the action is to move, then check to see if the object actually can move. if so, then it counts as "moving")
const int QUERY_collision = 1;
const int QUERY_canDivide = 2;
const int QUERY_heardNoise = 3;
const int QUERY_default = 4;        //just used for the sake of saving a sprite to this value
const int QUERY_noQuery = 5;        //had to move this up just to make things work better
const int QUERY_greyedOut = 6;      //used in the "edit" window
const int QUERY_editSelected = 7;

const int numQueries = 8;   // num queries = highest id value + 1
const int numUnselectableQueries = 4; //default, noQuery, greyedOut, editSelected

const int numNoises = 10;
const int numDataChoices = 11;

//windowType codes
const int WT_running = -1;
const int WT_paused = -2;
const int WT_editing = -3;
const int WT_editObjectSelected = -4;
const int WT_selectingDestination = -5;
const int WT_displayingConfirmChange = -6;
const int WT_confirmingBringToLife = -7;
const int WT_placingNewCell = -8;
const int WT_selectingData = -9;
