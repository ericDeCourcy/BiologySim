void clickWhenRunning(int mouseX, int mouseY)
{
    //if you click the pause button
    if((mouseY >= 640) && (mouseY <= 688) && (mouseX >= 0) && (mouseX <= 64))
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
        if(mousePos.x >= cancelIndvSelX && mousePos.x <= cancelIndvSelX + editWidth && mousePos.y >= cancelIndvSelY && mousePos.y <= cancelIndvSelY + editHeight)
        {
            individualSelected = -1;
        }
    }

}
