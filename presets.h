
void setFlowchartsToStart()
{
//this is the "first cell"
    flowcharts[0][0].state_number = 0;
    flowcharts[0][0].action = ACTION_born;
//        flowcharts[0][0].query_A = QUERY_noQuery;
    flowcharts[0][0].destination_default = 1;
    flowcharts[0][1].state_number = 1;
    flowcharts[0][1].action = ACTION_goRandDir;
    flowcharts[0][1].query_A = QUERY_collision;
    flowcharts[0][1].destination_A = 3;
    flowcharts[0][1].query_B = QUERY_moving;
    flowcharts[0][1].destination_B = 2;
    flowcharts[0][1].destination_default = 1;
    flowcharts[0][2].state_number = 2;
    flowcharts[0][2].action = ACTION_continueMoving;
    flowcharts[0][2].query_A = QUERY_collision;
    flowcharts[0][2].destination_A = 3;
    flowcharts[0][2].query_B = QUERY_moving;
    flowcharts[0][2].destination_B = 2;
    flowcharts[0][2].destination_default = 1;
    flowcharts[0][3].state_number = 3;
    flowcharts[0][3].action = ACTION_attemptToEat;
    flowcharts[0][3].query_A = QUERY_canDivide;
    flowcharts[0][3].destination_A = 4;
    flowcharts[0][3].destination_default = 1;
    flowcharts[0][4].state_number = 4;
    flowcharts[0][4].action = ACTION_splitAndDie;
    flowcharts[0][4].destination_default = 1;

    //this is the plant cell
    flowcharts[1][0].state_number = 0;
    flowcharts[1][0].action = ACTION_born;
    flowcharts[1][0].destination_default = 1;
    flowcharts[1][0].query_A = QUERY_noQuery;
    flowcharts[1][1].state_number = 1;
    flowcharts[1][1].action = ACTION_photosynth;
    flowcharts[1][1].destination_default = 1;
    flowcharts[1][1].query_A = QUERY_canDivide;
    flowcharts[1][1].destination_A = 2;
    flowcharts[1][2].state_number = 2;
    flowcharts[1][2].action = ACTION_splitAndDie;
    flowcharts[1][2].destination_default = 2;

    //This creates the first member of population, which is a plant cell
    population[0].alive = true;
    population[0].currentState = 0;
    population[0].directionMoving = -1;
    population[0].divisionMinimum = 500;
    population[0].energy = 250;
    population[0].inanimate = false;
    population[0].xPosition = 20;
    population[0].yPosition = 20;
    population[0].startingState = 0;
    population[0].species = 1;

    speciesColor[1] = CELL_green;

    population[1].alive = true;
    population[1].currentState = 0;
    population[1].directionMoving = -1;
    population[1].divisionMinimum = 500;
    population[1].energy = 2250;
    population[1].inanimate = false;
    population[1].xPosition = 22;
    population[1].yPosition = 22;
    population[1].startingState = 0;
    population[1].species = 0;
    population[1].stomachSize = 2;

    population[2].alive = true;
    population[2].currentState = 0;
    population[2].directionMoving = -1;
    population[2].divisionMinimum = 500;
    population[2].energy = 250;
    population[2].inanimate = false;
    population[2].xPosition = 11;
    population[2].yPosition = 4;
    population[2].startingState = 0;
    population[2].species = 0;
    population[2].stomachSize = 2;

    population[3].alive = true;
    population[3].currentState = 0;
    population[3].directionMoving = -1;
    population[3].divisionMinimum = 500;
    population[3].energy = 250;
    population[3].inanimate = false;
    population[3].xPosition = 6;
    population[3].yPosition = 17;
    population[3].startingState = 0;
    population[3].species = 0;
    population[3].stomachSize = 2;

    population[4].alive = true;
    population[4].currentState = 0;
    population[4].directionMoving = -1;
    population[4].divisionMinimum = 500;
    population[4].energy = 250;
    population[4].inanimate = false;
    population[4].xPosition = 30;
    population[4].yPosition = 23;
    population[4].startingState = 0;
    population[4].species = 0;
    population[4].stomachSize = 2;

    population[5].alive = true;
    population[5].currentState = 0;
    population[5].directionMoving = -1;
    population[5].divisionMinimum = 500;
    population[5].energy = 250;
    population[5].inanimate = false;
    population[5].xPosition = 1;
    population[5].yPosition = 3;
    population[5].startingState = 0;
    population[5].species = 0;
    population[5].stomachSize = 2;



    speciesColor[0] = CELL_red;

}

void emptyAllStomachs()
{
    for(int i = 0; i < popSize; i++)
    {
        for(int j = 0; j < maxStomachSize; j++)
        {
            population[i].stomach[j] = -1;
        }
    }
}
