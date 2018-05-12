

//should return -1-74 based on which object was selected in the chart
//-1 if no object is selected in the chart
//0-14 for Actions
//15-74 for queries
    //  QA  15-29
    //  QB  30-44
    //  QC  45-59
    //  QD  60-74


int editObjectSelected(int X, int Y)
{
    //this is the X distance from the far left edge of furthest left chart blocks
    int relX = X - firstChartBlockX;

    //this is the x distance from the left edge of the block to the left immediately
    int relXToBlock = relX % chartSpacingX;

    //if its too far over from the right such that its not on any chart block, RETURN -1
    if(relXToBlock > chartBlockWidth)
    {   return -1;   }

    int relY = Y - firstChartBlockY;
    int relYToBlock = relY % chartSpacingY;

    //same with too far down relative to blocks
    if(relYToBlock > chartBlockHeight)
    {   return -1;  }

    int xBlock = -1;
    int yBlock = -1;

    if(X < firstChartBlockX + chartSpacingX)
    {
        xBlock = 0;
    }
    else if(X < firstChartBlockX + 2*chartSpacingX)
    {
        xBlock = 1;
    }
    else if(X < firstChartBlockX + 3*chartSpacingX)
    {
        xBlock = 2;
    }
    else if(X < firstChartBlockX + 4*chartSpacingX)
    {
        xBlock = 3;
    }
    else
    {
        xBlock = 4;
    }
    std::cout << "xBlock number is: " << xBlock << "\n";

    if(Y < firstChartBlockY + chartSpacingY)
    {
        yBlock = 0;
    }
    else if(Y < firstChartBlockY + 2*chartSpacingY)
    {
        yBlock = 1;
    }
    else
    {
        yBlock = 2;
    }

    if(relYToBlock <= actionHeight)
    {
        return xBlock + 5*yBlock;           //within the action part of the block, returns that block number (actions have indexes 0-14 in chartDisplaySprite
    }
    else if(relYToBlock <= actionHeight + queryHeight)
    {
        return 15 + xBlock + 5*yBlock;      //indexes of QA in chartDisplaySprite (15-29)
    }
    else if(relYToBlock <= actionHeight + 2*queryHeight)
    {
        return 30 + xBlock + 5*yBlock;      //indexes of QB (30-44)
    }
    else if(relYToBlock <= actionHeight + 3*queryHeight)
    {
        return 45 + xBlock + 5*yBlock;      //QC  45-59
    }
    else
    {
        return 60 + xBlock + 5*yBlock;      //Default 60-74
    }

    std::cout << "ERROR in editObjectSelected()... reached impossible case\n";
    return -2;      //should never reach this, that means something wasn't covered
}
