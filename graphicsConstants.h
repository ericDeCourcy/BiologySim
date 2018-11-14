//This file only includes constants that are used for graphics and stuff. Just to help organize constant values a bit better

const int cellHolderX = 320;        //positions for celHolder
const int cellHolderY = 544;
const int cellHolderWidth = 160;    //width and height for cellHolder in PIXELS
const int cellHolderHeight = 32;

const int editButtonX = 160;
const int editWidth = 64;
const int editHeight = 32;
const int placeOneOptionsHeight = 48;

const int beginPlaceOneOptionsY = 312;
const int beginPlaceOneOptionsX = 808;

const int yesNoBlockWidth = 128;
const int yesNoBlockHalfWidth = 64;
const int yesNoBlockHeight = 32;
const int yesNoBlockX = 336;
const int yesNoBlockY = 704;

const int pauseX = 0;
const int pauseY = 640;
const int pauseHeight = 48;
const int pauseWidth = 64;

const int BMTLwidth = 112;
const int BMTLheight = 16;

const int QADataListX = 832;
const int QADataListY = 240;
const int QADataListWidth = 32;
const int QADataListHeight = 176;

//ALL THE SPRITE ID VALUES - SID stands for "sprite ID"
enum {  redCell_SID = 0,        //0
        greenCell_SID,          //1
        menuBlock_SID,          //2
        pause_SID,              //3
        options_SID,            //4
        pauseScreen_SID,        //5
        pauseChartObj_SID,      //6
        play_SID,               //7
        cellHolder_SID  };      //8

const int numSIDS = 8;

const int firstChartBlockX = 64;    //xcoordinate of first chart block in pause screen
const int firstChartBlockY = 64;
const int chartSpacingX = 144;      //spacing between top left corners of chart blocks in pause screen
const int chartSpacingY = 144;
const int actionHeight = 32;        // height in pixels of action word in block chart
const int chartBlockWidth = 96;     //width of action, query, etc
const int queryHeight = 16;         // height of query word in block chart thing
const int chartBlockHeight = actionHeight + 4*queryHeight;
const int fullChartMaxX = firstChartBlockX + 4*chartSpacingX + chartBlockWidth;
const int fullChartMaxY = firstChartBlockY + 2*chartSpacingY;
const int optionsToPlaceThere_y = 264;
const int menuBlock_X = 64;
const int menuBlock_Y = 640;

const int BMTL_x = 400;
const int BMTL_y = 656;

const int chartDataAmount = 225;     //equals the length of the "chartDisplayData" pointer

const int cancelIndvSelX = 592;
const int cancelIndvSelY = 688;
