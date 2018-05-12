int findNextFreeColor()
{
    bool colorUsed[numSpecies];

    for(int j = 0; j < numSpecies; j++)
    {
        colorUsed[j] = false;
    }

    for(int i = 0; i < numSpecies; i++)
    {
        if(speciesPop[i] > 0 && !speciesIsWaiting[i])
        {
            colorUsed[speciesColor[i]] = true;
        }
    }

    for(int k = 0; k < numSpecies; k++)
    {
        if(!colorUsed[k])
        {
            return k;
        }
    }

    return -1;
}
