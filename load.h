//This file loads the data in from save.txt and saves it's values to things like flowcharts, population, and gameMap.
//Depends on variables.h
///////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

#include "noiseStuff.h"
//#include "variables.h"
    //includes "dataTypes.h"
        //includes "constants.h"
            //includes "graphicsConstants.h"

int load()      //dunno if the int thing on the beginning is necesarry. Doesn't need to return a value; it's just editing global variables
{
    ifstream loadFile;

    std::cout << "it entered the read loop\n";
    std::string line;

    loadFile.open("save.txt");

    if(loadFile.is_open())
    {
        std::cout << "loadfile is open\n";
        for(int x = 0; x < numSpecies; x++)
        {
            for(int y = 0; y < numSpotsPer; y++)
            {
                //Okay, this sucks, but it only runs once so whatever.
                //each one of these blocks reads one variable from the line in the savefile and saves it
                //to its corresponding spot in the flowcharts array
                int temp;

                //this one saves state_number
                getline(loadFile,line,',');
                std::stringstream stateno(line);


                if(!(stateno >> temp))
                {   temp = 0;   }

                flowcharts[x][y].state_number = temp;

                //action
                getline(loadFile,line,',');
                std::stringstream action(line);

                if(!(action >> temp))
                {   temp = 0;   }

                flowcharts[x][y].action = temp;

                //query_a
                getline(loadFile,line,',');
                std::stringstream qa(line);

                if(!(qa >> temp))
                {   temp = 0;   }

                flowcharts[x][y].query_A = temp;

                //query_b
                getline(loadFile,line,',');
                std::stringstream qb(line);

                if(!(qb >> temp))
                {   temp = 0;   }

                flowcharts[x][y].query_B = temp;

                //query_c
                getline(loadFile,line,',');
                std::stringstream qc(line);

                if(!(qc >> temp))
                {   temp = 0;   }

                flowcharts[x][y].query_C = temp;

                //destination_a
                getline(loadFile,line,',');
                std::stringstream da(line);

                if(!(da >> temp))
                {   temp = 0;   }

                flowcharts[x][y].destination_A = temp;

                //destination_b
                getline(loadFile,line,',');
                std::stringstream db(line);

                if(!(db >> temp))
                {   temp = 0;   }

                flowcharts[x][y].destination_B = temp;

                //destination_c
                getline(loadFile,line,',');
                std::stringstream dc(line);

                if(!(dc >> temp))
                {   temp = 0;   }

                flowcharts[x][y].destination_C = temp;

                //destination_default
                getline(loadFile,line,',');
                std::stringstream dd(line);

                if(!(dd >> temp))
                {   temp = 0;   }

                flowcharts[x][y].destination_default = temp;
            }
            //this should cover the blank space between each flowchart in the save file
//               getline(loadFile,line);
        }

        //this for loop does the same thing as the two above except for reading in population information
        for(int z = 0; z < popSize; z++)
        {
            //species
            getline(loadFile,line,',');
            std::stringstream spec(line);

            int temp;
            if(!(spec >> temp))
            {   temp = 0;   }

            population[z].species = temp;

            //alive
            getline(loadFile,line,',');
            std::stringstream alive(line);

            if(!(alive >> temp))
            {   temp = 0;   }

            population[z].alive = temp;

            //cellType
 /*           getline(loadFile,line,',');
            std::stringstream type(line);

            if(!(type >> temp))
            {   temp = 0;   }

            population[z].cellType = temp;  */

            //currentState
            getline(loadFile,line,',');
            std::stringstream state(line);

            if(!(state >> temp))
            {   temp = 0;   }


            population[z].currentState = temp;

            //directionMoving
            getline(loadFile,line,',');
            std::stringstream dir(line);

            if(!(dir >> temp))
            {   temp = 0;   }

            population[z].directionMoving = temp;

            //divisionMinimum
            getline(loadFile,line,',');
            std::stringstream div(line);

            if(!(div >> temp))
            {   temp = 0;   }

            population[z].divisionMinimum = temp;

            //energy
            getline(loadFile,line,',');
            std::stringstream ener(line);

            if(!(ener >> temp))
            {   temp = 0;   }

            population[z].energy = temp;

            //inanimate
            getline(loadFile,line,',');
            std::stringstream inan(line);

            if(!(inan >> temp))
            {   temp = 0;   }

            population[z].inanimate = temp;

            //startingState
            getline(loadFile,line,',');
            std::stringstream start(line);

            if(!(start >> temp))
            {   temp = 0;   }

            population[z].startingState = temp;

            //xPos
            getline(loadFile,line,',');
            std::stringstream xp(line);

            if(!(xp >> temp))
            {   temp = 0;   }

            population[z].xPosition = temp;

            //yPos
            getline(loadFile,line,',');
            std::stringstream yp(line);

            if(!(yp >> temp))
            {   temp = 0;   }

            population[z].yPosition = temp;

            //add in the rest of the population components and stuff
        }

        //loads map
        for(int a = 0; a < mapWidth; a++)
        {
            for(int b = 0; b < mapHeight; b++)
            {
                int temp = -1;

                getline(loadFile,line,',');
                std::stringstream convert(line);

                if(!(convert >> temp))
                {   temp = 0;   }

                gameMap[a][b] = temp;
            }
        }

        //loads species colors
        for(int c = 0; c < numSpecies; c++)
        {
            int temp = -1;

            getline(loadFile,line,',');
            std::stringstream convert(line);

            if(!(convert >> temp))
            {   temp = 0;   }

            speciesColor[c] = temp;
        }
    }
}

int save()
{
    ofstream saveFile;

    saveFile.open("save.txt");

    for(int a = 0; a < numSpecies; a++)
    {
        for(int c = 0; c < numSpotsPer; c++)    //the c variable was created after the b variable in the for loop below. Crappy naming scheme but eh whatever
        {
            saveFile << flowcharts[a][c].state_number << ",";
            saveFile << flowcharts[a][c].action << ",";
            saveFile << flowcharts[a][c].query_A << ",";
            saveFile << flowcharts[a][c].query_B << ",";
            saveFile << flowcharts[a][c].query_C << ",";
            saveFile << flowcharts[a][c].destination_A << ",";
            saveFile << flowcharts[a][c].destination_B << ",";
            saveFile << flowcharts[a][c].destination_C << ",";
            saveFile << flowcharts[a][c].destination_default << ",\n";
        }
 //       saveFile << "\n";  //adds an extra blank line between every species in the savefile
    }

    for(int b = 0; b < popSize; b++)
    {
        saveFile << population[b].species << ",";
        saveFile << population[b].alive << ",";
 //       saveFile << population[b].cellType << ",";
        saveFile << population[b].currentState << ",";
        saveFile << population[b].directionMoving << ",";
        saveFile << population[b].divisionMinimum<< ",";
        saveFile << population[b].energy << ",";
        saveFile << population[b].inanimate << ",";
        saveFile << population[b].startingState << ",";
        saveFile << population[b].xPosition << ",";
        saveFile << population[b].yPosition << ",\n";
    }

    //saves all gameMap info
    for(int d = 0; d < mapWidth; d++)
    {
        for(int e = 0; e < mapHeight; e++)
        {
            saveFile << gameMap[d][e] << ",";
        }
        saveFile << "\n";
    }

    for(int e = 0; e < numSpecies; e++)
    {
        saveFile << speciesColor[e] << ",";
    }

    saveFile.close();
}
