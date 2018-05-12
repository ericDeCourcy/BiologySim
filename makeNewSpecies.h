
void makeNewSpecies(int originalSpecies, int newSpecies, int changeLocation, int changeValue, int destinationValue, int dataValue, bool sameLink, bool isNew)
{
    //first, duplicate the original species
    for(int i = 0; i < numSpotsPer; i++)
    {
        flowcharts[newSpecies][i] = flowcharts[originalSpecies][i];
    }

    //then execute the changeValue at changeLocation
    if(changeLocation < 15) //action
    {
        flowcharts[newSpecies][changeLocation].action = changeValue;
        flowcharts[newSpecies][changeLocation].actionData = dataValue;
        if(isNew)
        {
            flowcharts[newSpecies][changeLocation].destination_default = destinationValue;
        }
    }
    else if(changeLocation < 30) //query A
    {
        flowcharts[newSpecies][changeLocation - 15].query_A = changeValue;
        flowcharts[newSpecies][changeLocation - 15].qAData = dataValue;
        flowcharts[newSpecies][changeLocation - 15].destination_A = destinationValue;
    }
    else if(changeLocation < 45) //query B
    {
        flowcharts[newSpecies][changeLocation - 30].query_B = changeValue;
        flowcharts[newSpecies][changeLocation - 30].qBData = dataValue;
        flowcharts[newSpecies][changeLocation - 30].destination_B = destinationValue;
    }
    else if(changeLocation < 60) //query C
    {
        flowcharts[newSpecies][changeLocation - 45].query_C = changeValue;
        flowcharts[newSpecies][changeLocation - 45].qCData = dataValue;
        flowcharts[newSpecies][changeLocation - 45].destination_C = destinationValue;
    }
    else if(changeLocation < 75) // default
    {
        flowcharts[newSpecies][changeLocation - 60].destination_default = destinationValue;
    }


    if(!sameLink)
    {
        //make sure to add the link
        speciesLink[newSpecies] = originalSpecies;

        //and change the "waiting" thing
        speciesIsWaiting[newSpecies] = true;
    }



}
