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
        //        Sleep(0.001);     took this out... i Think it makes the game run faster
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
                                                                    //coordinates answer set based on direction of move
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
        std::cout << "gameMap[" << answer.x << "][" << answer.y << "] = " << gameMap[answer.x][answer.y] << "\n";
        answer.x = startX;      //answer becomes starting coordinates
        answer.y = startY;
    }
    else
    {
        std::cout << "gameMap[" << answer.x << "][" << answer.y << "] = " << MC_emptySpace << "\n";
    }
    return answer;
}

void moveIndividual(int individualNum, int xInit, int yInit, int xFinal, int yFinal)
{
    gameMap[xInit][yInit] = MC_emptySpace;
    gameMap[xFinal][yFinal] = individualNum;

    population[individualNum].xPosition = xFinal;
    population[individualNum].yPosition = yFinal;
}

void determineMapChanges()
{
    //fill drawObj with all -1's
    for(int c = 0; c < (popSize + mineralPopSize); c++)
    {
        drawObj[c].cellColor = -1;
        drawObj[c].x = -1;
        drawObj[c].y = -1;
    }

    for(int a = 0; a < popSize; a++)    //for all individuals in population, if alive, create a drawObj for them at the index of their population id num
    {
        if(population[a].alive)
        {
            drawObj[a].x = population[a].xPosition;
            drawObj[a].y = population[a].yPosition;
            drawObj[a].cellColor = speciesColor[population[a].species];
        }
    }

    for(int b = 0; b < mineralPopSize; b++) //for all minerals, if they arent type -1 (non mineral...?), create a draw obj for them at index = thier mineral pop num + popSize
    {
        if(mineralPop[b].type != -1)
        {
            drawObj[b + popSize].x = mineralPop[b].x;
            drawObj[b + popSize].y = mineralPop[b].y;
            drawObj[b + popSize].cellColor = mineralPop[b].type;
        }
    }

    //clear toDraw
    for(int e = 0; e < mapWidth; e++)
    {
        for(int f = 0; f < mapHeight; f++)
        {
            toDraw[e][f] = -1;
        }
    }

    //check to see if this is different from the lastSet]
    //if it is, add the needed changes to toDraw
    // 0-19 corresponds to cell color
    // 50 corresponds to water tile
    // 100-109 corresponds to mineralType + 100

    //for every pop id and mineral id num...
    for(int d = 0; d < (popSize + mineralPopSize); d++)
    {
        //if the cell color, x or y position of that id num is different in the lastSet versus the currentSet (AKA drawObj)...
        if((drawObj[d].cellColor != lastSet[d].cellColor) || (drawObj[d].x != lastSet[d].x) || (drawObj[d].y != lastSet[d].y))
        {
            if(d < popSize) //for cells and NOT minerals
            {
                //if the toDraw currently in the spot that that id was in during last set is -1 (meaning that nothing is in that spot now), draw some water there (covers up previous cell)
                if((lastSet[d].x >= 0) && (lastSet[d].y >= 0) && toDraw[lastSet[d].x][lastSet[d].y] == -1)
                {   toDraw[lastSet[d].x][lastSet[d].y] = 50;  }

                //and set toDraw at the spot of drawObj[d] to whatever the corresponding cell color is
                toDraw[drawObj[d].x][drawObj[d].y] = drawObj[d].cellColor;
            }
            else
            {
                //if the toDraw of wherever that mineral Id's x and y were last cycle is -1, draw a water tile in that spot
                if((lastSet[d].x >= 0) && (lastSet[d].y >= 0) && toDraw[lastSet[d].x][lastSet[d].y] == -1)
                {   toDraw[lastSet[d].x][lastSet[d].y] = 50;  }

                //and set toDraw equal to that minerals "cellColor" + 100 to make it correspond to a mineral to be drawn
                toDraw[drawObj[d].x][drawObj[d].y] = drawObj[d].cellColor + 100;
            }
        }
    }

    //looks like this is useless
    //clear lastSet
/*    for(int h = 0; h < (popSize + mineralPopSize); h++)
    {
        lastSet[h].cellColor = -1;
        lastSet[h].x = -1;
        lastSet[h].y = -1;
    }   */

    //finally, set lastSet equal to drawObj
    for(int g = 0; g < (popSize + mineralPopSize); g++)
    {
        lastSet[g].cellColor = drawObj[g].cellColor;
        lastSet[g].x = drawObj[g].x;
        lastSet[g].y = drawObj[g].y;
    }
}






