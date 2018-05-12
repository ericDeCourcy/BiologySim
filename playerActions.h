coordinates spotClicked(int mouseX, int mouseY)
//returns x = -2 if you click in one of the placeable options spots
{
    coordinates answer;

    //if the mouse is clicked outside of the window
    if(mouseX >= mapWidth*16 + 104 || mouseX < 0 || mouseY >= mapHeight*16+100 || mouseY < 0)
    {
        answer.x = -1;
        answer.y = -1;
    }

    //if the spot clicked is within one selectable spots
    else if(mouseX >= mapWidth*16 + 8 && mouseY >= optionsToPlaceThere_y)
    {
        answer.x = -2;  //this is the code for clicking in the optionsToPlaceThere space
        answer.y = (mouseY - (optionsToPlaceThere_y + 48) )/ 16;
        std::cout << "you clicked in the placeable options spot!\n";
    }

    //return the spot that is experiencing the click
    else
    {
        answer.x = mouseX/16;
        answer.y = mouseY/16;
    }
    return answer;
}
