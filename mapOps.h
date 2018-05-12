//This file is to contain any functions that modify the GameMap or pertain to doing stuff with it
///////////////////////////////////////////////////////////////////////////////////////////////////

#include "load.h"
    //includes "variables.h"
        //includes "dataTypes.h"
            //includes "constants.h"
                //includes "graphicsConstants.h"


coordinates isEmptySpace(int x, int y)  //checks area around x,y for first open spot, going clockwise starting at north
                                        //once it finds an open spot, returns the coordinates of that spot
                                        //if it doesn't find an open spot, returns coordinates -1,-1
{
    coordinates answer;

    bool north_ok = false;  //These represent whether the cells adjacent to the starting cell are OK to divide into
    bool south_ok = false;
    bool east_ok = false;
    bool west_ok = false;
    bool direction_chosen = false;

    answer.x = -1;  //these are only returned if an open spot is not found
    answer.y = -1;

    if(y > 0 && gameMap[x][y-1] == MC_emptySpace)
    {
       north_ok = true;
    }
/*    else if(y > 0 && x < mapWidth-1 && gameMap[x+1][y-1] == MC_emptySpace)
    {
        answer.x = x+1;
        answer.y = y-1;
    }   */
    if(x < mapWidth-1 && gameMap[x+1][y] == MC_emptySpace)
    {
        east_ok = true;
    }
/*    else if(x < mapWidth-1 && y < mapHeight-1 && gameMap[x+1][y+1] == MC_emptySpace)
    {
        answer.x = x+1;
        answer.y = y+1;
    }   */
    if(y < mapHeight-1 && gameMap[x][y+1] == MC_emptySpace)
    {
        south_ok = true;
    }
/*    else if(y < mapHeight-1 && x > 0 && gameMap[x-1][y+1] == MC_emptySpace)
    {
        answer.x = x-1;
        answer.y = y+1;
    }   */
    if(x > 0 && gameMap[x-1][y] == MC_emptySpace)
    {
        west_ok = true;
    }
/*    else if(x > 0 && y > 0 && gameMap[x-1][y-1] == MC_emptySpace)
    {
        answer.x = x-1;
        answer.y = y-1;
    }   */

//    std::cout << " N/E/S/W: " << north_ok << "," << east_ok << "," << south_ok << "," << west_ok << "\n";

    if(north_ok && !east_ok && !south_ok && !west_ok)
    {
        answer.x = x;
        answer.y = y-1;
        direction_chosen = true;
    }
    else if(!north_ok && east_ok && !south_ok && !west_ok)
    {
        answer.x = x+1;
        answer.y = y;
        direction_chosen = true;
    }
    else if(!north_ok && !east_ok && south_ok && !west_ok)
    {
        answer.x = x;
        answer.y = y+1;
        direction_chosen = true;
    }
    else if(!north_ok && !east_ok && !south_ok && west_ok)
    {
        answer.x = x+1;
        answer.y = y;
        direction_chosen = true;
    }

    while(!direction_chosen && !(!north_ok && !east_ok && !west_ok && !south_ok))
    {
        Sleep(0.001);
        int choice = rand() % 4;
//        std::cout << "rand: " << choice << "\n";

        if(choice == 0 && north_ok)
        {
            answer.x = x;
            answer.y = y-1;
            direction_chosen = true;
        }
        else if(choice == 1 && east_ok)
        {
            answer.x = x+1;
            answer.y = y;
            direction_chosen = true;
        }
        else if(choice == 2 && south_ok)
        {
            answer.x = x;
            answer.y = y+1;
            direction_chosen = true;
        }
        else if(choice == 3 && west_ok)
        {
            answer.x = x-1;
            answer.y = y;
            direction_chosen = true;
        }
    }

    return answer;
}

coordinates doMove(int directionMoving, int startX, int startY)     //Given direction, returns coordinates of a move in that direction
                                                                    //Coordinate answer is modified if:
                                                                    //  1) new coordinate is off of the map
                                                                    //  2) value of new coordinate in game map != -1 (-1 corresponds to no individual/object present)
{
    coordinates answer;
    answer.x = startX;
    answer.y = startY;

    switch(directionMoving)
    {
        case 0: answer.y = startY - 1;
                break;
        case 1: answer.y = startY - 1;
                answer.x = startX + 1;
                break;
        case 2: answer.x = startX + 1;
                break;
        case 3: answer.y = startY + 1;
                answer.x = startX + 1;
                break;
        case 4: answer.y = startY + 1;
                break;
        case 5: answer.y = startY + 1;
                answer.x = startX - 1;
                break;
        case 6: answer.x = startX - 1;
                break;
        case 7: answer.y = startY - 1;
                answer.x = startX - 1;
                break;
    }

    if(answer.x > mapWidth - 1)
    {
        answer.x = mapWidth -1;
    }
    else if(answer.x < 0)
    {
        answer.x = 0;
    }
    if(answer.y > mapHeight - 1)
    {
        answer.y = mapHeight -1;
    }
    else if(answer.y < 0)
    {
        answer.y = 0;
    }
    if(gameMap[answer.x][answer.y] != MC_emptySpace)   //if at the destination spot in gameMap, there is already an individual
    {
        answer.x = startX;      //answer becomes starting coordinates
        answer.y = startY;
    }
    return answer;
}




