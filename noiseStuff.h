#include "variables.h"


void clearSounds()
{
    for(int i = 0; i < popSize; i++)
    {
        allSoundCodes[i].originX = -1;
        allSoundCodes[i].originY = -1;
        allSoundCodes[i].sound = -1;
    }
}


//whenever a sound matching what you want is found, the X and Y distance to it is added to a running total. Thus, an average direction can be determined.
//that direction is what is returned
int checkForSoundSource(int x, int y, int sound)    //returns direction of sound source. If no direction, or if no sound, return -1
{
    int xDiff = 0;  //if origin of sound is greater than x on average, this will be positive
    int yDiff = 0;
    bool hasBeenFound = false;

    for(int i = 0; i < popSize; i++)
    {
        if(allSoundCodes[i].sound == sound)
        {
            hasBeenFound = true;
            if(allSoundCodes[i].originX > x)
            {
                xDiff++;
            }
            else if(allSoundCodes[i].originX < x)
            {
                xDiff--;
            }

            if(allSoundCodes[i].originY > y)
            {
                yDiff++;
            }
            else if(allSoundCodes[i].originY < y)
            {
                yDiff--;
            }
        }
    }

    if(hasBeenFound)
    {
        if(xDiff > 0)
        {
            if(yDiff > 0)
            {
                return 3;
            }
            else if(yDiff < 0)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else if(xDiff < 0)
        {
            if(yDiff > 0)
            {
                return 5;
            }
            else if(yDiff < 0)
            {
                return 7;
            }
            else
            {
                return 6;
            }
        }
        else
        {
            if(yDiff > 0)
            {
                return 4;
            }
            else if(yDiff < 0)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }
    }
    else
    {
        return -1;
    }
}
