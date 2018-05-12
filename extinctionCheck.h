//if a species has population zero or less, any species that is linked to it AND waiting to come alive (dunno how you could have one but not the other)
//will be set to not waiting, have no species link, and the speciesBeingPlaced will be set to -1
void extinctionate(int species)
{

    if(speciesPop[species] < 1)
    {
        for(int i = 0; i < numSpecies; i++)
        {
            if(speciesLink[i] == species && speciesIsWaiting[i] == true)
            {
                speciesIsWaiting[i] = false;
                speciesLink[i] = -1;
                speciesBeingPlaced = -1;
            }
        }
    }
}
