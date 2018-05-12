//  This file contains methods that run act while the game is running
///////////////////////////////////////////////////////////////////////

//operates on global variables, edits the global "cells to display" struct
void prepForDisplay()
{
    for(int n = 0; n < popSize; n++)
    {
        if(population[n].alive)
        {

        }
    }
}

sf::Sprite cellSpriteGetter(int color)
{
    switch(color)
    {
        case CELL_red:
        {
            return redCell;
            break;
        }
        case CELL_green:
        {
            return greenCell;
            break;
        }
        default:
        {
            return nothing;
        }
    }
}
