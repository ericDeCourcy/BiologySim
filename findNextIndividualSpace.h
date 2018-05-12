int findNextIndividualSpace()
{
    int newIndividualNumber = -1;       //if no population spot is open, newIndividualNumber = -1
    for(int x = 0; x < popSize; x++)
    {
        if(!population[x].alive)
        {
            newIndividualNumber = x;    //newIndividualNumber = the ID of the first open spot
            return newIndividualNumber;               //this exits the for loop because we're done looking for an open spot
        }
    }

    return newIndividualNumber;
}
