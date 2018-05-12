//This file contains everything that pertains to individuals doing actions on their flowcharts
////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "mapOps.h"
    //includes "load.h"
        //includes "variables.h"
            //includes "dataTypes.h"
                //includes "constants.h"

bool queryEval(int query, individual subject, bool hasCollided, int individualNum)
{
    bool queryMet = false;
    switch(query)
    {
    case QUERY_moving:
        {
            if(subject.directionMoving != -1)
            {
                queryMet = true;
            }
            break;
        }
    case QUERY_collision:
        {
            queryMet = hasCollided;
            break;
        }
    case QUERY_canDivide:
        {
            cout << "subject.energy & subject.divisionMinimum " << subject.energy << ", " << subject.divisionMinimum << "\n";
            if(subject.energy > subject.divisionMinimum)
            {
                cout << "energy > divisionMin\n";
                queryMet = true;
            }
            break;
        }
    case QUERY_heardNoise:
        {
            std::cout << "it herd a noise\n";
            if(checkForSoundSource(subject.xPosition, subject.yPosition, flowcharts[subject.species][subject.currentState].actionData) > 0)
            {
                queryMet = true;
                queryEvalData[individualNum] = checkForSoundSource(subject.xPosition, subject.yPosition, flowcharts[subject.species][subject.currentState].actionData);
            }
        }
    }
    return queryMet;
}

eatingInfo attemptToEat(int x, int y, int eaterEnergy)      //test all the nearby spots to find out what spot has the highest energy that the individual doing the eating
                                                            //can consume. If its larger than the eating individual's energy, it can't consume.
                                                            //Once it has that, returns the amount of energy that the individual getting eaten has and the ID number of
                                                            //the individual getting eaten
                                                            //If there are no individuals to eat, returns a -1 for both energy and "individual getting eaten" value
{
    eatingInfo answer;

    //energy of everything nearby ("Directional Energies"). index 0 means North, 1 NE, and so on to 7 = NW. (-1) means no energy and no individual
    int DE[8];

    const int DE_emptySpace = -1;   //means that there is no energy and no individual in that space

    for(int n = 0; n < 8; n++)  //for each space, DE[n] = DE_emptySpace;
    {
        DE[n] = DE_emptySpace;
    }

    //gets the energies of each space around the eater, if there is something with energy there
    if(y > 0 && gameMap[x][y-1] != MC_emptySpace)
    {
        DE[0] = population[gameMap[x][y-1]].energy;
    }
    if(y > 0 && x < mapWidth-1 && gameMap[x+1][y-1] != MC_emptySpace)
    {
        DE[1] = population[gameMap[x+1][y-1]].energy;
    }
    if(x < mapWidth-1 && gameMap[x+1][y] != MC_emptySpace)
    {
        DE[2] = population[gameMap[x+1][y]].energy;
    }
    if(x < mapWidth-1 && y < mapHeight-1 && gameMap[x+1][y+1] != MC_emptySpace)
    {
        DE[3] = population[gameMap[x+1][y+1]].energy;
    }
    if(y < mapHeight-1 && gameMap[x][y+1] != MC_emptySpace)
    {
        DE[4] = population[gameMap[x][y+1]].energy;
    }
    if(y < mapHeight-1 && x > 0 && gameMap[x-1][y+1] != MC_emptySpace)
    {
        DE[5] = population[gameMap[x-1][y+1]].energy;
    }
    if(x > 0 && gameMap[x-1][y] != MC_emptySpace)
    {
        DE[6] = population[gameMap[x-1][y]].energy;
    }
    if(x > 0 && y > 0 && gameMap[x-1][y-1] != MC_emptySpace)
    {
        DE[7] = population[gameMap[x-1][y-1]].energy;
    }

    int bestPossibleIndex = -1;  //index of best possible eating choice. Best choice is highest in energy without being greater than the energy of the individual doing the eating.
    for(int n = 0; n < 8; n++)  //for all DE[n]...
    {
        if(DE[n] != DE_emptySpace && bestPossibleIndex == DE_emptySpace && DE[n] < eaterEnergy)   //if bestPossibleIndex has not been defined yet (still equals DE_emptySpace) and DE[n] doesn't correspond to an empty space AND DE[n] is less than the energy that the eating guy has
        {
            bestPossibleIndex = n;  //best index is now that index
        }
        else if(bestPossibleIndex > -1 && DE[n] > DE[bestPossibleIndex] && DE[n] < eaterEnergy)    //if BPI has been defined and energy of n is more than energy at BPI AND DE[n] is less than the energy that the eating guy has,
        {
            bestPossibleIndex = n;              //BPI now equals n
        }
    }

    if(bestPossibleIndex == -1) //means that nothing in the above for loop changed BPI value, so all choices should be an empty space
    {
        answer.energyEaten = 0;
        answer.individualNumber = -1;
    }
    else
    {
        answer.energyEaten = DE[bestPossibleIndex];
        switch(bestPossibleIndex)       //for whatever the BPI was, find out what map spot that corresponds to
        {
            case 0: answer.individualNumber = gameMap[x][y-1];
                    break;
            case 1: answer.individualNumber = gameMap[x+1][y-1];
                    break;
            case 2: answer.individualNumber = gameMap[x+1][y];
                    break;
            case 3: answer.individualNumber = gameMap[x+1][y+1];
                    break;
            case 4: answer.individualNumber = gameMap[x][y+1];
                    break;
            case 5: answer.individualNumber = gameMap[x-1][y+1];
                    break;
            case 6: answer.individualNumber = gameMap[x-1][y];
                    break;
            case 7: answer.individualNumber = gameMap[x-1][y-1];
                    break;
        }
    }

    return answer;      //returns the amount of energy eaten and the number of the individual that got eaten
}

void clearEvalData()
{
    for(int i = 0; i < popSize; i++)
    {
        queryEvalData[i] = -1;
    }
}
