
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
    flowcharts[0][4].destination_default = 4;

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
    population[0].divisionMinimum = 100;
    population[0].energy = 50;
    population[0].inanimate = false;
    population[0].xPosition = 20;
    population[0].yPosition = 20;
    population[0].startingState = 0;
    population[0].species = 1;

    speciesColor[0] = CELL_red;

    population[1].alive = true;
    population[1].currentState = 0;
    population[1].directionMoving = -1;
    population[1].divisionMinimum = 100;
    population[1].energy = 50;
    population[1].inanimate = false;
    population[1].xPosition = 0;
    population[1].yPosition = 0;
    population[1].startingState = 0;
    population[1].species = 0;

    speciesColor[1] = CELL_green;

}
