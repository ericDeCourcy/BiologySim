

//function "was yes clicked"
    //returns 1 for yes
    // 0 for nothing
    // -1 for no clicked



//function resetAllEditVars





//function to determine which windowtype to go to next and make any needed changes to game data
void handleDisplayingConfirmChange(sf::Vector2i mousePos)
{
    //6dIII.V-1) if you clicked the yes
    if(yesClicked(mousePos.x, mousePos.y))
    {
        //find the next species with zero pop && not waiting
        if(speciesIsWaiting[selectedSpecies])   //this applies if the species is waiting
        {
            makeNewSpecies(selectedSpecies, selectedSpecies, editObjectClicked, confirmData.newChoice, destinationSelected, choicesData, true, isNewAction);
            evolutionPoints[speciesLink[selectedSpecies]] = evolutionPoints[speciesLink[selectedSpecies]] - minPoints;
        }
        else    //this applies if the species is a new one
        {
            makeNewSpecies(selectedSpecies, findNextEmptySpecies(), editObjectClicked, confirmData.newChoice, destinationSelected, choicesData, false, isNewAction);
            evolutionPoints[selectedSpecies] = evolutionPoints[selectedSpecies] - minPoints;
        }

        windowType = WT_paused;
        editObjectClicked = -1;
        placeOneObjectClicked = -1;
        placeOneObject_hasBeenChosen = false;
        destinationSelected = -1;
        isNewAction = false;
        choiceRequiresData = false;
        choicesData = -1;
    }

    //else if you click the no button
    else if(mousePos.x >= (yesNoBlockX + yesNoBlockHalfWidth) && mousePos.x <= (yesNoBlockX + yesNoBlockWidth) && mousePos.y >= yesNoBlockY && mousePos.y <= (yesNoBlockY + yesNoBlockHeight))
    {
        windowType = WT_paused;
        editObjectClicked = -1;
        placeOneObjectClicked = -1;
        placeOneObject_hasBeenChosen = false;
        destinationSelected = -1;
        isNewAction = false;
        choiceRequiresData = false;
        choicesData = -1;
    }
}
