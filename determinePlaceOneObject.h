void determinePlaceOneObject()
{
    if(placeOneObject_hasBeenChosen == false)
    {
        if(editObjectClicked < 15)
        {
            placeOneObject_isAction = true;

            if(mousePos.y < beginPlaceOneOptionsY + actionHeight*(numActions-numUnselectableActions))
            {
                placeOneObjectClicked = (mousePos.y - beginPlaceOneOptionsY)/(actionHeight) + 1;    //the +1 is added because "be born" isnt a selectable action. It just works
                placeOneObject_hasBeenChosen = true;
            }
            else
            {
                placeOneObjectClicked = -1;
            }
        }

        else if(editObjectClicked < 60)           // if(editObjectClicked >= 15)
        {

            placeOneObject_isAction = false;    //basically says you aren't selecting actions

            //6dVIII-1bI)   Sets placeOneObjectClicked to the query clicked, unless mousePos.y is lower than bottom of lowest query.
            //Then, placeOneObjectClicked = -1
            if(mousePos.y < beginPlaceOneOptionsY + queryHeight*(numQueries-numUnselectableQueries)) //if mousePos.y is above the position of the end of the list of placeable query options
            {
                placeOneObjectClicked = (mousePos.y - beginPlaceOneOptionsY)/queryHeight;
                placeOneObject_hasBeenChosen = true;
            }
            else
            {
                placeOneObjectClicked = -1;
            }
        }
    }
    if(placeOneObject_hasBeenChosen == true)
    {

        //6dVIII-2a)    if the currently selected species has enough evolutionPoints to modify, AND displayingConfirmChange = false then set
        //	displayingConfirmChange = true, set confirmData.original appropriately, set confirmData.newChoice appropriately
        // if not enough evolution points, display a message with std::out
        std::cout << "entered 6dVIII-2a block\n";

        if((evolutionPoints[selectedSpecies] >= minPoints || evolutionPoints[speciesLink[selectedSpecies]]) && displayingConfirmChange == false)
        {
            std::cout << "evolutionPoints[selectedSpecies] >= minPoints\n";
            std::cout << "evolutionPoints[" << selectedSpecies << "] = " << evolutionPoints[selectedSpecies] << "\n";


            std::cout << "chartObjectClicked = " << editObjectClicked << "\n";
            std::cout << "this corresponds to query/action num: " << chartDisplaySprite[editObjectClicked] << "\n";


            confirmData.original = chartDisplaySprite[editObjectClicked];


            //setting confirmData.newChoice appropriately
            if(placeOneObject_isAction)
            {
                confirmData.newChoice = placeOneObjectClicked;      //happens regardless

                if(!actionRequiresData(placeOneObjectClicked))
                {
                    cout << "ACTION DOES NOT NEED DATA\n";

                    displayingConfirmChange = true;
                    windowType = WT_displayingConfirmChange;

                    if(isNewAction)
                    {
                        windowType = WT_selectingDestination;
                        displayingConfirmChange = false;
                    }
                }
                else
                {
                    windowType = WT_selectingData;
                    choiceRequiresData = true;
                }

            }
            else
            {
                confirmData.newChoice = placeOneObjectClicked;

                if(!queryRequiresData(placeOneObjectClicked))
                {
                    windowType = WT_selectingDestination;
                }
                else
                {
                    windowType = WT_selectingData;
                    choiceRequiresData = true;
                }

            }

            //display some text here that asks the user if they are sure, making sure to show them where they are making the change and what they are changing what for
                //if they click yes then change the flowchart
                //and subtract from evolution points
            //if they click no then exit from that window and set placeOneObjectClicked back to -1 and placeOneObject_hasBeenChosen to false
        }
        //6dVIII-2b)    else, reset the time left to display error messages
        else    //implies they don't have enough points
        {
            std::cout << "You don't have enough evolution points!\n";
            NEP_errorTime = errorLength + tickClock;
        }
    }
}
