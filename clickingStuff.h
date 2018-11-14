bool pauseClicked(int x, int y)
{
    if((y >= 640) && (y <= 688) && (x >= 0) && (x <= 64))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void clickWhenRunning(int mouseX, int mouseY)
{
    //if you click the pause button
    if(pauseClicked(mouseX, mouseY))
    {
        windowType = WT_paused;
    }
    else
    {
        coordinates temp = spotClicked(mouseX, mouseY);
        if(gameMap[temp.x][temp.y] != MC_emptySpace)
        {
            individualSelected = gameMap[temp.x][temp.y];
        }
        //if you click inside the "cancel" button only
        if(mousePos.x >= cancelIndvSelX && mousePos.x <= cancelIndvSelX + editWidth && mousePos.y >= cancelIndvSelY && mousePos.y <= cancelIndvSelY + editHeight)
        {
            individualSelected = -1;
        }
    }

}

bool yesClicked(int x, int y)
{
    if(x >= yesNoBlockX && x <= (yesNoBlockX + yesNoBlockHalfWidth) && y >= yesNoBlockY && y <= (yesNoBlockY + yesNoBlockHeight))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool noClicked(int x, int y)
{
    if(x >= (yesNoBlockX + yesNoBlockHalfWidth) && x <= (yesNoBlockX + yesNoBlockWidth) && y >= yesNoBlockY && y <= (yesNoBlockY + yesNoBlockHeight))
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool BMTLClicked(int x, int y)
{
    if((x >= BMTL_x) && (x <= (BMTL_x + BMTLwidth)) && (y >= BMTL_y) && (y <= (BMTL_y + BMTLheight)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool editButtonClicked(int x, int y)
{
    if((y >= cellHolderY) && (y <= cellHolderY + editHeight) && (x >= cellHolderX - 160) && (x <= cellHolderX - 160 + editWidth))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QADataListClicked(int x, int y)
{
    if(x >= QADataListX && x < (QADataListX + QADataListWidth) && y >= QADataListY && y < (QADataListY + QADataListHeight))
    {
        return true;
    }
    else
    {
        return false;
    }
}
