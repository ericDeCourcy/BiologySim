
//given a species number
    //define an array of ints "answer"  --  [numSpotsPer][8]
    //for every flowchart entry
        //save a sprite id in "answer" for its action
        //save a sprite id in "answer" for its queries {A,B,C}
        //save a sprite id in "answer" for its destinations {A,B,C,default}
    //return that shitttttt

void loadChart(logicState* chart)
{
                        //entry 0 will be action code, 1 will be x coord, 2 will be y coord
                        //all entries will follow this pattern. First entry is value, next is x, next is y
                        //0-44 covers actions and thier coordinates
                        //45-89 covers queryA/coords
                        //90-134 covers B/coords
                        //135-179   C/coords
                        //180-224 does defaults
                        //225-404 handles destinations
                            //225-269   destinationA
                            //270-314   destinationB
                            //315-359   destinationC
                            //360-404   destinationDefault

    for(int i = 0; i < 75; i++)     //new way of doing things
                                    //seperate spots for sprite, x and y
                                    //0-14 does actions
                                    //15-29 does QA
                                    //30-44 does QB
                                    //45-59 does QC
                                    //60-75 does defaults
    {
        if(i < 15)
        {
            chartDisplaySprite[i] = chart[i].action;
            chartDisplayData[i] = chart[i].actionData;
        }
        else if(i < 30)
        {
            chartDisplaySprite[i] = chart[i-15].query_A;
            chartDisplayData[i] = chart[i-15].qAData;
        }
        else if(i < 45)
        {
            chartDisplaySprite[i] = chart[i-30].query_B;
            chartDisplayData[i] = chart[i-30].qBData;
        }
        else if(i < 60)
        {
            chartDisplaySprite[i] = chart[i-45].query_C;
            chartDisplayData[i] = chart[i-45].qCData;
        }
        else
        {   if(chart[i-60].action > -1)
            {
                chartDisplaySprite[i] = QUERY_default;
            }
            else
            {
                chartDisplaySprite[i] = -1;
            }
        }


    }

    int j = 0;
    for(int i = 0; i < 60; i=i+4) //this is for destinations.
                                //0-3 for spot 1, with it being QA,QB,QC,Default
                                //and so on
    {
        chartDisplayDest[i] = chart[j].destination_A;
        chartDisplayDest[i+1] = chart[j].destination_B;
        chartDisplayDest[i+2] = chart[j].destination_C;
        chartDisplayDest[i+3] = chart[j].destination_default;
        j++;
    }
}



int cellSelectXFind(int species)
{
    int returnVal = cellHolderX + species*16;
    if(species > 9)
    {
        returnVal = returnVal - 160;
    }
    return returnVal;
}

int cellSelectYFind(int species)
{
    int returnVal = cellHolderY;
    if(species > 9)
    {
        returnVal = returnVal + 16;
    }
    return returnVal;
}

int cellHolderSelector(int clickX, int clickY)
{
    int relativeX = clickX - cellHolderX;
    int holderColSelected = (relativeX)/16;

    int relativeY = clickY - cellHolderY;
    int holderRowSelected = relativeY/16;

    int species = holderColSelected + 10*holderRowSelected;

    if((speciesPop[species] > 0) || (speciesIsWaiting[species]))
    {
        return species;
    }
    else
    {
        return -1;
    }
}
