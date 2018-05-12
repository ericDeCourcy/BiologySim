
int findNextEmptySpecies()
{
    int i = 0;

    for(i = 0; i < numSpecies; i++)
    {
        if((speciesPop[i] == 0) && !speciesIsWaiting[i])
        {
            return i;
        }
    }

    return -1;
}
