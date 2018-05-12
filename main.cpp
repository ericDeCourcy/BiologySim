//#include "loadTextures.h"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

#include <time.h>
#include <windows.h>
#include <stdlib.h>


#include "individualOps.h"
    //includes "mapOps.h"
        //includes "load.h"


            //includes "variables.h"
                //includes "dataTypes.h"
                    //includes "constants.h"
                        //includes "graphicsConstants.h"
#include "flowchartOps.h"
#include "playerActions.h"
#include "pauseActions.h"
#include "editActions.h"
#include "spriteLoader.h"
//#include "gameOps.h"
//#include "spriteLoader.h"
    //includes "sprites.h"
#include "spriteFileNames.h"
    //includes "spriteIDs.h"
#include "presets.h"
#include "UserInterfaceFuncs.h"
#include "makeNewSpecies.h"
#include "findNextEmptySpecies.h"
#include "findNextIndividualSpace.h"
#include "findNextFreeColor.h"
#include "extinctionCheck.h"
#include "displayTextOnScreen.h"
#include "requiresData.h"
#include "determineDataClicked.h"
#include "clickingStuff.h"

using namespace std;

//only returns true or false if the query is met or not. The main function decides what to do with this true/false data


int main()
{
    //  1)  seeds random nums
    srand(time(NULL));

    //  2)  initializes points, chart coordinates, gameMap to empty
    pointInitializer();
    chartDisplayInitializer();
    isWaitingInitializer();
    speciesLinkInitializer();
    mapInitializer();
    clearSounds();
    clearEvalData();

    //defines flowcharts in general
    //for every flowchart spot used, make sure to declare action and default destination

    //  3)  Asks user for input, then loads if need be
    std::cout << "Enter 0 to start new, enter any other number for load: " << "\n";
    int userChoice = 0;
    std::cin >> userChoice;

    if(userChoice == 0)
    {
        setFlowchartsToStart();
    }
    else
    {
        load();
    }

    //  4)  Create the main window
      sf::RenderWindow app(sf::VideoMode(mapWidth*16 + sideMenuWidth, mapHeight*16 + menuHeight), "SFML window");

    //  5)  Creates font, loads all needed sprites
    if(!gameFont.loadFromFile("font/times.ttf"))
    {
        return EXIT_FAILURE;
    }


    nameThoseSprites();

    sf::Sprite allSprites[last_id+1];
    std::cout << "last_id: " << last_id << "\n";
    sf::Texture allTextures[last_id+1];

    for(int i = 0; i <= last_id; i++)
    {
        std::cout << "loaded: " << sprite_filenames[i] << "\n";

        if(!allTextures[i].loadFromFile(sprite_filenames[i]))
        {   return EXIT_FAILURE;    }
        allSprites[i].setTexture(allTextures[i]);

    }

    //loads the greencellapp.draw(tempSprite); sprite
/*    sf::Texture greenCellTexture;
    if (!greenCellTexture.loadFromFile("greenCell.gif"))
    {   return EXIT_FAILURE;    }                //exits game if file cannot be found
    sf::Sprite greenCell(greenCellTexture); */

    sf::Texture menuBlockTexture;
    if (!menuBlockTexture.loadFromFile("menuBlock.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite menuBlock(menuBlockTexture);

    sf::Texture pauseTexture;
    if (!pauseTexture.loadFromFile("pause.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite pause(pauseTexture);

    sf::Texture optionsTexture;
    if (!optionsTexture.loadFromFile("options.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite options(optionsTexture);

    sf::Texture pauseScreenTexture;
    if (!pauseScreenTexture.loadFromFile("pauseScreen.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite pauseScreen(pauseScreenTexture);

    sf::Texture pauseChartObjTexture;
    if (!pauseChartObjTexture.loadFromFile("pauseChartObj.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite pauseChartObj(pauseChartObjTexture);

    sf::Texture playTexture;
    if (!playTexture.loadFromFile("play.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite play(playTexture);

    sf::Texture cellHolderTexture;
    if (!cellHolderTexture.loadFromFile("cellHolder.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite cellHolder(cellHolderTexture);

    sf::Texture cellSelectTexture;
    if(!cellSelectTexture.loadFromFile("cellSelect.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite cellSelect(cellSelectTexture);

    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile("background.gif"))
    {   return EXIT_FAILURE;    }
    sf::Sprite background(backgroundTexture);

    sf::Texture actionsTexture;
    if (!actionsTexture.loadFromFile("actions.gif"))
    {   return EXIT_FAILURE;    }

    sf::Sprite actions[numActions];

    for(int i = 0; i < numActions; i++)     //saves multiple sprites from one texture (good for memory use according to SFML website)
    {
        actions[i].setTexture(actionsTexture);
        actions[i].setTextureRect(sf::IntRect(0,i*32,96,32));
    }


//Queries set to texture here:
    sf::Texture queriesTexture;
    if(!queriesTexture.loadFromFile("queries.gif"))
    {   return EXIT_FAILURE;     }

    sf::Sprite queries[numQueries];

    for(int i = 0; i < numQueries; i++)
    {
        queries[i].setTexture(queriesTexture);
        queries[i].setTextureRect(sf::IntRect(0,i*16,96,16));
    }

//QAdata set to textures here:
    sf::Texture QAdataTexture;
    if(!QAdataTexture.loadFromFile("QAdata.gif"))
    {   return EXIT_FAILURE;    }

    sf::Sprite QAdata[numQAdataOptions];

    for(int i = 0; i < numQAdataOptions; i++)
    {
        QAdata[i].setTexture(QAdataTexture);
        QAdata[i].setTextureRect(sf::IntRect(0,i*16,32,16));
    }

//loadingt all cells texture
    sf::Texture allCellsTexture;
    if(!allCellsTexture.loadFromFile("21cells.gif"))
    {   return EXIT_FAILURE;    }

    sf::Sprite cells[numCells];

    for(int b = 0; b < 2; b++)
    {
        for(int a = 0; a < 10; a++)
        {
            cells[a+b*10].setTexture(allCellsTexture);
            cells[a+b*10].setTextureRect(sf::IntRect(a*16,b*16,16,16));
        }
    }
    cells[20].setTexture(allCellsTexture);
    cells[20].setTextureRect(sf::IntRect(0,32,16,16));

    sf::Sprite nothing;

    sf::Texture destinationsTexture;
    if(!destinationsTexture.loadFromFile("destinations.gif"))
    {   return EXIT_FAILURE;    }

    sf::Sprite destinations[numSpotsPer];

    sf::Texture editTexture;
    if(!editTexture.loadFromFile("Edit.gif"))       //rename gif later maybe. is "Edit" instead of all lowercase
    {
        return EXIT_FAILURE;
    }
    sf::Sprite edit(editTexture);

    sf::Texture cancelTexture;
    if(!cancelTexture.loadFromFile("cancel.gif"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite cancel(cancelTexture);

    for(int i = 0; i < numSpotsPer; i++)
    {
        destinations[i].setTexture(destinationsTexture);
        destinations[i].setTextureRect(sf::IntRect(0,i*16,48,16));
    }

    sf::Texture sideMenuTexture;
    if(!sideMenuTexture.loadFromFile("sideMenu.gif"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite sideMenu(sideMenuTexture);

    sf::Texture placeOneTexture;
    if(!placeOneTexture.loadFromFile("placeOne.gif"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite placeOne(placeOneTexture);

    sf::Texture selectASpotTexture;
    if(!selectASpotTexture.loadFromFile("selectASpot.gif"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite selectASpot(selectASpotTexture);

    sf::Texture currentlyInSpotTexture;
    if(!currentlyInSpotTexture.loadFromFile("currentlyInSpot.gif"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite currentlyInSpot(currentlyInSpotTexture);

    sf::Texture optionsToPlaceThereTexture;
    if(!optionsToPlaceThereTexture.loadFromFile("optionsToPlaceThere.gif"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite optionsToPlaceThere(optionsToPlaceThereTexture);

    sf::Texture yesNoBlockTexture;
    if(!yesNoBlockTexture.loadFromFile("yesNoBlock.gif"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite yesNoBlock(yesNoBlockTexture);

    sf::Texture indicatorBarVertTexture;
    if(!indicatorBarVertTexture.loadFromFile("indicatorBarVert.gif"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite indicatorBarVert(indicatorBarVertTexture);

    sf::Texture selectSoundTexture;
    if(!selectSoundTexture.loadFromFile("selectSound.gif"))
    {
        return EXIT_FAILURE;
    }
    sf::Sprite selectSound(selectSoundTexture);

    mouseClicked = false;

	//  6)  Start the game loop (while app is open)
    while (app.isOpen())
    {
//        std::cout << "starting appisOpen loop\n";
        // Process events like keypress, etc

        //  6a) poll for event "closing window". If so, close app
        sf::Event event;
        while (app.pollEvent(event))
        {
            // if the event is the user closing the window, close the app
            if (event.type == sf::Event::Closed)
                app.close();
        }

        //  6b) For loop, runs once per ms for frameRatePeriod milliseconds. If mouse is clicked within that time, mouseClicked = true
        //      mouseClicked is never set to false within this loop
        for(int i = 0; i < frameRatePeriod; i++)    //checks every millisecond for whether the mouse left Button is clicked. Runs for however many times framerate period is
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                mouseClicked = true;
            }
            //get mouse position
            Sleep(1);   //sleeps 1ms. This way, we can check the mouse roughly every millisecond
        }

        //  6c) increment tickClock
        tickClock ++;

        //if there's been a falling edge on the mouse button click
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouseClicked == true)        //where all the clicking stuff happens
        {
            //sets mouseClicked to false
            mouseClicked = false;

            //  6dII) gets mousePos (mouse position)
            mousePos = sf::Mouse::getPosition(app);
            std::cout << mousePos.x << ",";
            std::cout << mousePos.y;
            std::cout << " are the coordinates\n";

            //6dIII.V) if the window type is displayingConfirmChange
            if(windowType == WT_displayingConfirmChange)
            {
                //6dIII.V-1) if you clicked the yes
                if(mousePos.x >= yesNoBlockX && mousePos.x <= (yesNoBlockX + yesNoBlockHalfWidth) && mousePos.y >= yesNoBlockY && mousePos.y <= (yesNoBlockY + yesNoBlockHeight))
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

            //  6dIV) if the pause button is clicked, changes sets paused = !paused
            //      really ought to change this to paused = false;
            else if((mousePos.y >= 640) && (mousePos.y <= 688) && (mousePos.x >= 0) && (mousePos.x <= 64))   //position of the pause button
            {
                std::cout << "pause button clicked \n";
          /*      if(windowType == WT_running)
                {
                    windowType = WT_paused;
                }   */
                if(!windowType == WT_running)
                {
                    windowType = WT_running;
                }
            }

            if(windowType == WT_running)
            {
                clickWhenRunning(mousePos.x, mousePos.y);
            }

            //  6dV) if paused and not editing, if the cellHolder was clicked, sets selectedSpecies to whichever species was clicked
            else if(windowType == WT_paused && (mousePos.y >= cellHolderY) && (mousePos.y <= cellHolderY + cellHolderHeight) && (mousePos.x >= cellHolderX) && (mousePos.x <= cellHolderX + cellHolderWidth))
            {
                int speciesClicked = cellHolderSelector(mousePos.x, mousePos.y);

                if(speciesClicked > -1)
                {
                    selectedSpecies = speciesClicked;
                }
            }

            //if species is waiting and window is paused and clicked on the bring me to life button
            else if(windowType == WT_paused && speciesIsWaiting[selectedSpecies] && speciesBeingPlaced != selectedSpecies && (mousePos.x >= BMTL_x) && (mousePos.x <= (BMTL_x + BMTLwidth)) && (mousePos.y >= BMTL_y) && (mousePos.y <= (BMTL_y + BMTLheight)))
            {
                speciesBeingPlaced = selectedSpecies;
                speciesColor[speciesBeingPlaced] = findNextFreeColor();

            }

            //  6dVI)   turns editing to true if the EDIT button is clicked
            //turns editing to false if CANCEL is clicked (it is in the same spot)
            //resets editObjectClicked to -1 and edit_somethingClicked = false
            else if((windowType == WT_paused || windowType == WT_editing || windowType == WT_editObjectSelected) && (mousePos.y >= cellHolderY) && (mousePos.y <= cellHolderY + editHeight) && (mousePos.x >= cellHolderX - 160) && (mousePos.x <= cellHolderX - 160 + editWidth))
            {
                if(windowType == WT_paused)
                {
                    windowType = WT_editing;
                }
                else
                {
                    windowType = WT_paused;
                }

                displayingConfirmChange = false;
                placeOneObjectClicked = -1;
                editObjectClicked = -1;
                edit_somethingClicked = false;
                placeOneObject_hasBeenChosen = false;
                isNewAction = false;
            }

            //  6dVII)  if editing and something hasn't been clicked (selected for replacement), allows you to click an object that is flashing grey.
            //chconfirmData.newChoice = placeOneObjectClicked;      //happens regardless anges editObjectClicked to value of object clicked based on mouse click position
            else if(windowType == WT_editing && (mousePos.x >= firstChartBlockX) && (mousePos.x <= fullChartMaxX) && (mousePos.y >= firstChartBlockY) && (mousePos.y <= fullChartMaxY))
            {
                //6dVII-1)  sets editObjectClicked = editObjectSelected( , )
                //if it doesn't return -1, edit_somethingClicked is set to true
                editObjectClicked = editObjectSelected(mousePos.x, mousePos.y);
                if(editObjectClicked > -1)
                {
                    windowType = WT_editObjectSelected;
                }


                //6dVII-2)  Basically, if you selected a spot that can't be edited yet or is spot 0, then edObjClicked = -1 and
                //          edit_somethClicked = false;
                //checks to make sure the object that the position you clicked has something in the position before it.
                //if, for instance, queryC is selected without a queryB existing for that chartblock, then it is an invalid object click
                //this will change edit_somethingClicked to false IFF the previous object has value less than zero
                //ALSO - this statement is true if you click chart spot 0 (action = be born). Every cell needs to be born.
                //thus, you cannot select chart spot 0 to edit
                if((editObjectClicked < 60) && (((editObjectClicked < 15) && !(chartDisplaySprite[editObjectClicked - 1] > -1)) || ((editObjectClicked >= 15) && !(chartDisplaySprite[editObjectClicked-15] > -1)) || (editObjectClicked == 0)))
                {
                    editObjectClicked = -1;
                    windowType = WT_editing;
                }

                //this is for the default query case specifically
                else if((editObjectClicked > 59) && (chartDisplaySprite[editObjectClicked % 15] > -1))
                {
                    windowType = WT_selectingDestination;
                    placeOneObjectClicked = QUERY_default;

                }
                //this is for new actions specifically
                else if((editObjectClicked < 15) && (chartDisplaySprite[editObjectClicked] == -1))
                {
                    isNewAction = true;
                }

            }

            //6dVIII)   if paused, editing, edit_somethingClicked, x pos within placeOneOptions space, y pos below placeOneOptions upper bound
            //ONLY CHECKS if the player has clicked within the x bounds and under the upper y bound of the list of placeOneOptions
            //inside this loop
            //YOU NEED TO CHECK
            //whether a placeOneOption has been selected based on whether it is actions or queries
            // and whether the options extend as far down as the player has clicked (this if statement has no lower y bound)
            else if(windowType == WT_editObjectSelected && (mousePos.x >= beginPlaceOneOptionsX) && (mousePos.x < beginPlaceOneOptionsX + chartBlockWidth) && (mousePos.y >= beginPlaceOneOptionsY))
            {
                //6dVIII-1) if a placeOneOption has not been clicked, sets placeOneObject_hasBeenChosen to true and placeOneObject_isAction to appropriate value based on user click
 //               std::cout << "placeOneObject_hasBeenChosen = " << placeOneObject_hasBeenChosen << "\n";
                if(placeOneObject_hasBeenChosen == false)
                {
                    std::cout << "editObjectClicked: " << editObjectClicked << "\n";
 //                   std::cout << "entered 6dVIII-1 if-block AND editObjectClicked = " << editObjectClicked << "\n";
                    //6dVIII-1a)    if the editObjectClicked was an action, set placeOneObject_isAction = true;
                    //              set placeOneObjectClicked equal to the action number clicked if the user clicks within the options list
                    if(editObjectClicked < 15)
                    {
                        placeOneObject_isAction = true;

                        if(mousePos.y < beginPlaceOneOptionsY + actionHeight*(numActions-numUnselectableActions))
                        {
                            placeOneObjectClicked = (mousePos.y - beginPlaceOneOptionsY)/(actionHeight);
                            placeOneObject_hasBeenChosen = true;
                        }
                        else
                        {
                            placeOneObjectClicked = -1;
                        }


                        std::cout << "setting placeOneObject_isAction to true\n";
                        //do whatever for the actions blocks here
                    }

                    //6dVIII-1b)    if the object selected to edit is a query (not an action), set placeOneObject_isAction = false
                    else if(editObjectClicked < 60)           // if(editObjectClicked >= 15)
                    {

                        placeOneObject_isAction = false;    //basically says you aren't selecting actions
                        std::cout << "setting placeOneObject_isAction to false\n";

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


                //6dVIII-2) if placeOneObject_hasBeenChosen = true
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

            //only for actions or queries that have metadata associated with them
            else if(windowType == WT_selectingData)
            {
                if(mousePos.x >= QADataListX && mousePos.x < (QADataListX + QADataListWidth) && mousePos.y >= QADataListY && mousePos.y < (QADataListY + QADataListHeight))
                {
                    choicesData = determineDataClicked(mousePos.y);
                    windowType = WT_selectingDestination;
                }
            }



            else if(windowType == WT_selectingDestination)
            {
                destinationSelected = (editObjectSelected(mousePos.x, mousePos.y) % 15);

                if(destinationSelected != -1)
                {
                    windowType = WT_displayingConfirmChange;
                }

            }

            //do whatever with the mouse coordinates. Keep in mind that itll detect mouse clicks outside the window so its gotta
            //account for this and make sure to basically not do anything if you click outside the  windowowow

        }

        //6e)   if the game is not paused...
        if(windowType == WT_running)
        {
            //6eI)   for n = 0 to (popSize -1)
            for(int n = 0; n < popSize; n++)    //popSize is a const, so this will evaluate for every possible living creature
            {
                //6eI-1)    if the individual has 0 or less energy, set it to dead and set it's gameMap space to empty
                if(population[n].energy <= 0)   //check to see if population[n] has any energy. If no, kills it and removes it from gameMap
                {
      //              std::cout << "individual " << n << " died\n";
                    population[n].alive = false;
                    gameMap[population[n].xPosition][population[n].yPosition] = MC_emptySpace;

                }

                //6eI-2)    if the individual is alive, not inanimate, and has energy > 0...
                if(population[n].alive && !population[n].inanimate && population[n].energy > 0)     //only does evaluation of actions if the creature is alive and NOT inanimate and energy is greater than 0
                {                               //the energy > 0 thing is a redundancy of the above
                    //6eI-2a)    set hasCollided to false
                    bool hasCollided = false;   //for every turn, this value starts as false.
                                                //changes to true if the individual attempts to move and then doesn't/cant.
                                                //used in the "has collided" query

                    //this statement just for troubleshooting
                    if(population[n].species == 2)
                    {
                        std::cout << "species 2 detected! Action is: " << flowcharts[population[n].species][population[n].currentState].action << "\n";
                        std::cout << "the current state is: " << population[n].currentState << "\n";
                    }

     //               std::cout << "the action: " << flowcharts[population[n].species][population[n].currentState].action << "\n";
     //               std::cout << "the default destination: " << flowcharts[population[n].species][population[n].currentState].destination_default << "\n";
     //               std::cout << "the species: " << population[n].species << "\n";


                    //6eI-2b)   do a switch case on the current individual's current action
                    //do whatever action for the part of the flowchart that individual is on
                    std::cout << "flowcharts[" << population[n].species << "][" << population[n].currentState << "].action = " << flowcharts[population[n].species][population[n].currentState].action << "\n";
                    switch(flowcharts[population[n].species][population[n].currentState].action)      //switch based on the action of the current flowchart spot the individual is on
                    {
                        //6eI-2bI)  if the action is to go in a random direction
                        case ACTION_goRandDir:
                        {
                            //6eI-2bI-1)    pick a random direction, get it's location, test location via the "doMove" method
                            int direction = rand() % 8; //picks a new direction
                            coordinates newLocation;    //makes empty coordinates for the new location
                            newLocation = doMove(direction, population[n].xPosition, population[n].yPosition);  //attempts to move in the direction determined above. If the individual cannot move to there
                                                                                                                //for whatever reason, the newLocation variable will be set to whatever spot it is possible
                                                                                                                //to move to
                            //6eI-2bI-2)    if the new coordinates are the same as the old, set directionMoving to "None" and hasCollided to True
                            if(newLocation.x == population[n].xPosition && newLocation.y == population[n].yPosition)

                            {
    //                            std::cout << "Collision: " << population[n].xPosition << ", " << population[n].yPosition << "\n";
                                population[n].directionMoving = DIR_none;
                                hasCollided = true;
                            }

                            //6eI-2bI-3)    if the new coordinates are not the same, then:
                            else    //else if its a different spot
                            {
                                //6eI-2bI-3a)   set gameMap at that spot to individuals ID value
                                gameMap[population[n].xPosition][population[n].yPosition] = n;

                                //6eI-2bI-3b)   set individual's x/y position to the new spot
                                population[n].xPosition = newLocation.x;
                                population[n].yPosition = newLocation.y;

                                //6eI-2bI-3c)   set direction moving to the correct direction
                                population[n].directionMoving = direction;

                                //6eI-2bI-3d)   set old gameMap spot to "empty"
                                gameMap[population[n].xPosition][population[n].yPosition] = MC_emptySpace; //the map spot where the individual was before is now -1 (no individual)

                                //6eI-2bI-3e)   decrease individuals energy by 1
                                population[n].energy--;
                            }
                            break;

                        }

                        //6eI-2bII) if the action is to continue moving
                        case ACTION_continueMoving:
                        {
                            //6eI-2bII-1)   use doMove & directionMoving to find new location
                            int direction = population[n].directionMoving;
                            coordinates newLocation;
                            newLocation = doMove(direction, population[n].xPosition, population[n].yPosition);

                            //6eI-2bII-2)   if newLocation is the same spot, set directionMoving to none and hasCollided to true
                            if(newLocation.x == population[n].xPosition && newLocation.y == population[n].yPosition)    //if after attempting to move, the individual is still in the same spot
                            {
     //                           std::cout << "Collision: " << population[n].xPosition << ", " << population[n].yPosition << "\n";
                                population[n].directionMoving = DIR_none;     //corresponds to no direction
                                hasCollided = true;
                            }

                            //6eI-2bII-3)   if newLocation is different, then do the same thing as 6eI-2bI-3
                            else
                            {
                                gameMap[population[n].xPosition][population[n].yPosition] = MC_emptySpace; //the map spot where the individual was before is now -1 (no individual)
                                population[n].xPosition = newLocation.x;
                                population[n].yPosition = newLocation.y;
                                population[n].directionMoving = direction;
                                gameMap[population[n].xPosition][population[n].yPosition] = n;  //the map spot where the individual is now is equal to the individuals ID value
                                population[n].energy--;
                            }
                            break;
                        }

                        //6eI-2bIII)    if the action is to attempt to eat...
                        case ACTION_attemptToEat:
                        {
                            //6eI-2bIII-1)  use attemptToEat to determine which, if any, spots nearby are best suited to be eaten
                            eatingInfo thisAttempt; //creates an "eating info" object
                            thisAttempt = attemptToEat(population[n].xPosition, population[n].yPosition, population[n].energy); //passes position and energy of individual into "attemptToEat" function to define eating info object created in last line

                            //6eI-2bIII-2)  if there is something to eat, add correct energy to individual, set eaten individual's "alive" value to false, and set the gameMap spot for that individual to empty
                            if(thisAttempt.individualNumber != -1)  //if the individual being eaten value DOES NOT correspond to no individual to eat. This should actually happen often. If the collision is with an object or a larger creature it'll return -1
                            {
                                population[n].energy = population[n].energy + thisAttempt.energyEaten;
                                population[thisAttempt.individualNumber].alive = false; //the individual being eaten now is set to "dead"
                                gameMap[population[thisAttempt.individualNumber].xPosition][population[thisAttempt.individualNumber].yPosition] = MC_emptySpace;
                            }
                            break;
                        }

                        //6eI-2bIV) if the action is "splitAndDie"...
                        case ACTION_splitAndDie:
                        {

                            //6eI-2bIV-1)   save coordinates of a free space to split to in "freeSpot"
                            //test to see if theres free space
                            coordinates freeSpot;       //coordinates of the spot where the new guy will go
                            freeSpot = isEmptySpace(population[n].xPosition, population[n].yPosition);  //free spot coordinates will be returned. If no free spot adjacent to individual, (-1,-1) will be returned

                            //test to see if theres a population spot open
                            //6eI-2bIV-2)   if there's space in the population, find the next individual ID that corresponds to "not alive"
                            int newIndividualNumber = findNextIndividualSpace();       //if no population spot is open, newIndividualNumber = -1

                            //6eI-2bIV-3)   if the freeSpot is valid and the newIndividualNumber (ID number) is valid...
                            if(freeSpot.x != -1 && freeSpot.y != -1 && newIndividualNumber != -1)   //if there is a free spot AND newIndividualNumber != -1
                            {
                                if(population[n].species != speciesLink[speciesBeingPlaced])
                                {
 //                                   std::cout << "got to line 701\n";
                                     //6eI-2bIV-3a)  new individual is created in new spot with identical features to old
                                    population[newIndividualNumber] = population[n];            //make an identical individual to the old
                                    population[newIndividualNumber].xPosition = freeSpot.x;     //put it in the freeSpot x and y positions
                                    population[newIndividualNumber].yPosition = freeSpot.y;
                                    gameMap[freeSpot.x][freeSpot.y] = newIndividualNumber;

                                }
                                else
                                {
                                    population[newIndividualNumber].species = speciesBeingPlaced;
                                    population[newIndividualNumber].xPosition = freeSpot.x;
                                    population[newIndividualNumber].yPosition = freeSpot.y;
                                    gameMap[freeSpot.x][freeSpot.y] = newIndividualNumber;
                                    population[newIndividualNumber].currentState = 0;
                                    population[newIndividualNumber].divisionMinimum = 100;
                                    population[newIndividualNumber].alive = true;
                                    population[newIndividualNumber].inanimate = false;

                                    speciesIsWaiting[speciesBeingPlaced] = false;
                                    speciesBeingPlaced = -1;
                                }

                                 //6eI-2bIV-3b)  both individuals set back to their starting spots on the flowchart
                                population[n].currentState = population[n].startingState;
                                population[newIndividualNumber].currentState = population[n].startingState;

                                //6eI-2bIV-3c)`new individual is given half of old individual's energy
                                population[newIndividualNumber].energy = (int)(population[n].energy/2);

                                //6eI-2bIV-3d)  old individual is given old energy minus new individual's energy. That way, energy is conserved (useful in the case of old energy being an odd number)
                                population[n].energy = population[n].energy - population[newIndividualNumber].energy;
 //                               std::cout << "energies of original and new: " << population[n].energy << ", " << population[newIndividualNumber].energy << "\n";

                                //6eI-2bVI-3e)  increment evolution points of the corresponding species by 1
                                evolutionPoints[population[n].species] += 1;

                            }
                            break;
                        }

                        //6eI-2bV)  if the action is to photosynthesize, add one energy to that individual
                        case ACTION_photosynth:
                        {
                            population[n].energy = population[n].energy+1;
                            break;
                        }

                        //6eI-2bVI) if the action is to be born, add the individual to the gameMap
                        case ACTION_born:   //just puts the object on the gameMap
                        {
                            gameMap[population[n].xPosition][population[n].yPosition] = n;
                            break;
                        }

                        case ACTION_makeNoise:
                        {
                            allSoundCodes[n].originX = population[n].xPosition;
                            allSoundCodes[n].originY = population[n].yPosition;
                            allSoundCodes[n].sound = flowcharts[population[n].species][population[n].currentState].actionData;
                            break;
                        }
                    }

                    //reset the query eval data
                    clearEvalData();

                    //6eI-2c)   perform queryEval function on each query, and save result as queryMetA (or B or C)
                    bool queryMetA = queryEval(flowcharts[population[n].species][population[n].currentState].query_A, population[n], hasCollided, n);
                    bool queryMetB = queryEval(flowcharts[population[n].species][population[n].currentState].query_B, population[n], hasCollided, n);
                    bool queryMetC = queryEval(flowcharts[population[n].species][population[n].currentState].query_C, population[n], hasCollided, n);

                    //6eI-2d)   if queryMetA is true, then sets individuals currentState to that destination. Else if B true, or C true do the same
                    if(queryMetA)
                    {
                        population[n].currentState = flowcharts[population[n].species][population[n].currentState].destination_A;
    //                    std::cout << "QA met\n";
                    }
                    else if(queryMetB)
                    {
                        population[n].currentState = flowcharts[population[n].species][population[n].currentState].destination_B;
    //                    std::cout << "QB met\n";
                    }
                    else if(queryMetC)
                    {
                        population[n].currentState = flowcharts[population[n].species][population[n].currentState].destination_C;
    //                    std::cout << "QC met\n";
                    }

                    //6eI-2e)   if no query is met, then sets individual's current state to the default
                    else    //do default if no A query
                    {
                        population[n].currentState = flowcharts[population[n].species][population[n].currentState].destination_default;

     //                   std::cout << "default destination: " << flowcharts[population[n].species][population[n].currentState].destination_default << "\n";
     //                   std::cout << "Default action taken\n";
                    }
     //               std::cout << "current State: " << population[n].currentState << "\n";


                }

                //6eI-3)    if the individual is inanimate, has zero energy, or something else, do things with it here (currently EMPTY)
                //this is where the else cases go. if less than zero energy, or inanimate and not alive or vice versa...
            }
        }

        clearSounds();

        //6f)   sets all elements of speciesPop to 0, then for every individual, if it is alive, add one to its species' correpsonding element in speciesPop
        //this totals the populations of every species currently
        for(int i = 0; i < numSpecies; i++)
        {
            speciesPop[i] = 0;
        }
        for(int i = 0; i < popSize; i++)
        {
            if(population[i].alive)    //will still record if its inanimate
            {
                speciesPop[population[i].species]++;
            }
        }

        //extinctionate function checks to see if pop is extinct and then affects the "speciesIsWaiting" array
        for(int i = 0; i < numSpecies; i++)
        {
            extinctionate(i);
        }

        //6g)   Clear screen
        app.clear();

        background.setPosition(0,0);
        app.draw(background);

        //6i)   if NEP_errorTime is > 0, display the "Not Enough Points" error message
        if(NEP_errorTime > tickClock)
        {
            errorString = errorPicker(NEP_errorTime, tickClock);
            textStringStream << errorString;
            textString = textStringStream.str();
            text.setString(textString);
            text.setCharacterSize(16);
            text.setPosition(268 + menuBlock_X, 64 + menuBlock_Y);
            text.setColor(sf::Color::Red);
            text.setFont(gameFont);
            app.draw(text);
            textStringStream.str("");   //this is IMPORTANT - it clears the string stream so that it can be used later
        }

        //6j)   if the game is running or you're placing a new cell
        if(windowType == WT_running || windowType == WT_placingNewCell)
        {
            //6jI)  for all individuals in population, setPosition and draw corresponding sprite
            for(int n = 0; n < popSize; n++)
            {
                sf::Sprite cellToDisplay;

                if(population[n].alive)
                {
                    cellToDisplay = cells[population[n].species];

                    cellToDisplay.setPosition(population[n].xPosition*16, population[n].yPosition*16);
                    app.draw(cellToDisplay);
                }
                if(n == individualSelected)
                {
                    sf::Sprite temp;
                    temp = allSprites[cellSelect_id];
                    temp.setPosition(population[n].xPosition*16, population[n].yPosition*16);
                    app.draw(temp);
                }
            }
        }
        else        //if paused...
        {
            //6kI)  draws pause screen background
            allSprites[pauseScreen_id].setPosition(32,32);
            app.draw(allSprites[pauseScreen_id]);

            //6kII) draws chartBlocks via for loops for spacing
            for(int x = firstChartBlockX; x <= 640;  x = x + chartSpacingX)
            {
                for(int y = firstChartBlockY; y <= 432; y = y + chartSpacingY)
                {
                    allSprites[pauseChartObj_id].setPosition(x,y);
                    app.draw(allSprites[pauseChartObj_id]);
                }
            }

            //6kIII)    loads the chart info for selected species, saves it to chartDisplaySprite array
            loadChart(flowcharts[selectedSpecies]);

            //6kIV) displays the chart info loaded above. Only displays Actions,Queries
            for(int i = 0; i < 75; i++)
            {
                //6kIV-1)   create temp sprite "thisGuy" used for displaying
                sf::Sprite thisGuy;

                //6kIV-2)   if the index value of that chart object is less than 15 (corresponds to action)
                if(i < 15)
                {
                    //6kIV-2a)  if the value for that chartDisplaySprite element is above -1 and doesn't correspond to the edit object that was clicked
                    if(chartDisplaySprite[i] > -1 && i != editObjectClicked)
                    {
                        if(windowType == WT_selectingDestination && (tickClock%2) == 1)
                        {
                            thisGuy = actions[ACTION_editSelected];
                        }
                        //6kIV-1aI) set the temp sprite to the corresponding sprite and set its placement on the screen
                        else
                        {
                            thisGuy = actions[chartDisplaySprite[i]];
                        }
                        thisGuy.setPosition(chartDisplayX[i], chartDisplayY[i]);
                    }

                    //6kIV-2b)  else...
                    else
                    {
                        //6kIV-2bI) Displays a constant yellow circle if:
                        //  The action/query before this exists (is > -1) AND
                        //  you are editing, AND
                        //  the edit object clicked is this object
                        if((chartDisplaySprite[i-1] > -1) && (windowType == WT_editObjectSelected || windowType == WT_displayingConfirmChange) && (editObjectClicked == i))
                        {
                            thisGuy = actions[ACTION_editSelected];
                            thisGuy.setPosition(chartDisplayX[i], chartDisplayY[i]);
                        }

                        //6kIV-2bII)    else if the previous chart obj existed, you are editing, and an editObject has NOT been clicked, Displays a greyed out space
                        else if((chartDisplaySprite[i-1] > -1) && windowType == WT_editing && (tickClock%2 == 1) && (editObjectClicked < 0))
                        {
                            thisGuy = actions[ACTION_greyedOut];
                            thisGuy.setPosition(chartDisplayX[i], chartDisplayY[i]);

                        }

                        //6kIV-2bIII)   else, sets the sprite used for displaying to nothing
                        else
                        {
                            thisGuy = nothing;
                        }
                    }
                }

                //6kIV-3)   else (if the i corresponds to that of an query)
                else
                {
                    //6kIV-3a)  if the query exists and isnt the editObject clicked, display it
                    if(chartDisplaySprite[i] > -1 && i != editObjectClicked)
                    {
                        thisGuy = queries[chartDisplaySprite[i]];
                        thisGuy.setPosition(chartDisplayX[i], chartDisplayY[i]);
                    }

                    //6kIV-3b)  else, if editing, and the query exists, and the action above it exists, and the editObjectClicked is this query, display a yellow circle where the query would be
                    else if((chartDisplaySprite[i%15] > -1) && (windowType == WT_editObjectSelected || windowType == WT_selectingDestination || windowType == WT_displayingConfirmChange) && (editObjectClicked == i) && ((chartDisplaySprite[i-15] > -1) || i > 59))
                    {
                        thisGuy = queries[QUERY_editSelected];
                        thisGuy.setPosition(chartDisplayX[i], chartDisplayY[i]);
                    }

                    //6kIV-3c)  else if; displays greyed out space if in editing
                    //if the action corresponding to that query (the %15 command) exists
                    //      and editing
                    //      and tick clock is odd
                    //      and the chart display info for the action(for QA) and the query before is not -1
                    else if((editObjectClicked < 0) &&(chartDisplaySprite[i%15] > -1) && windowType == WT_editing && (tickClock%2 == 1) && chartDisplaySprite[i-15] > -1)
                    {
                        thisGuy = allSprites[QUERY_greyedOut_id];
                        thisGuy.setPosition(chartDisplayX[i], chartDisplayY[i]);
                    }

                    //6kIV-3d)  else, sets thisGuy (temp sprite) to nothing
                    else
                    {
                        thisGuy = nothing;
                    }


                }

                //6kIV-4)   actually DRAW the temp sprite to the screen
                app.draw(thisGuy);
            }

            //6kV)  displays destinations. for i 0 through 59...
            for(int i = 0; i < 60; i++)
            {
                //6kV-1)    create temp sprite called thisGuy
                sf::Sprite thisGuy;

                //6kV-2)    if the destination for that i exists, and is less than 15...
                if(chartDisplayDest[i] > -1 && chartDisplayDest[i] < 15)
                {
                    //6kV-2a)   look up the corresponding destination sprite, set thisGuy equal to it, set position
                    thisGuy = destinations[chartDisplayDest[i]];
                    thisGuy.setPosition(chartDisplayDX[i],chartDisplayDY[i]);
                }

                //6kV-3)    draw thisGuy
                app.draw(thisGuy);
            }

            //displays all the data, if there is data to display
            for(int i = 0; i < 75; i++)
            {
                sf::Sprite thisGuy;

                if(chartDisplayData[i] > -1)
                {
                    thisGuy = QAdata[chartDisplayData[i]];
                    thisGuy.setPosition(chartDisplayX[i] + 64, chartDisplayY[i]);
                    app.draw(thisGuy);
                }
            }

            //6kVI) create a sprite called tempSprite (guess what it does)
            sf::Sprite tempSprite;

            //6kVII)    draws the cell holder for the pause menu
            allSprites[cellHolder_id].setPosition(cellHolderX,cellHolderY);
            app.draw(allSprites[cellHolder_id]);

            //6kVIII)   finds position of cellSelect, then sets it's position
            cellSelectX = cellSelectXFind(selectedSpecies);
            cellSelectY = cellSelectYFind(selectedSpecies);
            allSprites[cellSelect_id].setPosition(cellSelectX, cellSelectY);

            //6kIX) draws cellSelect if tickClock is odd
            if((tickClock%2) == 1)
            { app.draw(allSprites[cellSelect_id]); }

            //6kX) if not already editing, displays Edit button
            if(windowType == WT_paused)
            {
                edit.setPosition(editButtonX, cellHolderY);
                app.draw(edit);
            }

            //6kXI) else (if editing)...
            else
            {
                //6kXI-1)   set position of cancel sprite, then draw it
                cancel.setPosition(editButtonX, cellHolderY);
                app.draw(cancel);

                //6kXI-2)
                textStringStream << "Evolution Points: " << evolutionPoints[selectedSpecies];
                textString = textStringStream.str();
                text.setString(textString);
                text.setCharacterSize(16);
                text.setPosition(80,cellHolderY + 32);
                text.setColor(sf::Color::Red);
                text.setFont(gameFont);
                app.draw(text);
                textStringStream.str("");
            }


            //6kXII) draws the species currently present in the cell holder when the game is paused
            //For all possible cellHolder x,y values...
            for(int y = 0; y <= 1; y++)  //values of 544 and 560 only
            {
                for(int x = 0; x <= 9; x++)      //values every 16 pixels from 320 to 464
                {
                    //6lXII-1aI)    create a temporary sprite
                    sf::Sprite thisCell;

                    if(speciesPop[y*10 + x] > 0 || speciesBeingPlaced == (y*10 + x))
                    {

                        //6lXII-1aII)   set the color of the sprite to the color of the species. If no species, sets it to nothing. Does this solely based on color
                        thisCell = cells[y*10 + x];


/*                        switch(speciesColor[y*10 + x])
                        {
                        case CELL_green:
                            thisCell = allSprites[CELL_green_id];
                            break;
                        case CELL_red:
                            thisCell = allSprites[CELL_red_id];
                            break;
                        case CELL_lightBlue:
                            thisCell = allSprites[CELL_lightBlue_id];
                            break;
                        default:
                            thisCell = nothing;
                        }           */

                    }

                    else if(speciesIsWaiting[y*10 + x])
                    {
                        std::cout << "line 1083 reached\n";
                        thisCell = allSprites[CELL_grey_id];
                    }

                    thisCell.setPosition(cellHolderX + x*16, cellHolderY + y*16);      //NOTE this needs to be changed to match the cell color actually. Gotta save cell color as an aspect of species
                    app.draw(thisCell);
                }
            }
        }

        //6l)   if game isn't paused, draw the pause button. If paused, draw the play button in the same spot
        if(windowType == WT_running)
        {
            allSprites[pause_id].setPosition(0,640);
            app.draw(allSprites[pause_id]);

        }
        else
        {
            allSprites[play_id].setPosition(0,640);
            app.draw(allSprites[play_id]);
        }

        //6m)   draw the options button in the correct spot
        allSprites[options_id].setPosition(0,688);
        app.draw(allSprites[options_id]);

        //6n)   draw the menuBlock at the correct spot
        allSprites[menuBlock_id].setPosition(menuBlock_X,menuBlock_Y);
        app.draw(allSprites[menuBlock_id]);

        if(windowType == WT_selectingDestination)
        {
            if(!isNewAction)
            {
                textStringStream << "select the destination for if this query is met";
                textString = textStringStream.str();
                text.setString(textString);
                text.setCharacterSize(16);
                text.setPosition(160,640);
                text.setColor(sf::Color::Red);
                text.setFont(gameFont);
                app.draw(text);
                textStringStream.str("");
            }
            else
            {
                textStringStream << "select this block's default destination";
                textString = textStringStream.str();
                text.setString(textString);
                text.setCharacterSize(16);
                text.setPosition(160,640);
                text.setColor(sf::Color::Red);
                text.setFont(gameFont);
                app.draw(text);
                textStringStream.str("");
            }

        }

        if(windowType == WT_running && individualSelected != -1)
        {
            textStringStream << "This Individual's Energy: " << population[individualSelected].energy;
            textString = textStringStream.str();
            text.setString(textString);
            text.setCharacterSize(16);
            text.setPosition(80,656);
            text.setColor(sf::Color::Red);
            text.setFont(gameFont);
            app.draw(text);
            textStringStream.str("");

            textStringStream << "Evolution Points for this Species: " << evolutionPoints[individualSelected];
            textString = textStringStream.str();
            text.setString(textString);
            text.setCharacterSize(16);
            text.setPosition(80,672);
            text.setColor(sf::Color::Red);
            text.setFont(gameFont);
            app.draw(text);
            textStringStream.str("");

            textStringStream << "Population for this Species: " << speciesPop[individualSelected];
            textString = textStringStream.str();
            text.setString(textString);
            text.setCharacterSize(16);
            text.setPosition(80,688);
            text.setColor(sf::Color::Red);
            text.setFont(gameFont);
            app.draw(text);
            textStringStream.str("");

            sf::Sprite temp;
            temp = cancel;
            temp.setPosition(592,688);
            app.draw(temp);
        }

        if(windowType == WT_editing || windowType == WT_paused)
        {

            if(speciesIsWaiting[selectedSpecies] && speciesBeingPlaced == -1)
            {
                app.draw(displayTextOnScreen(160,640,"This cell is not living yet. You can continue editing it until you want to bring it to life. \nWould you like to bring it to life?"));

                textStringStream << "Until this cell is brought to life, any modifications on it will not create a new cell and will spend\nevolution points from species #" << speciesLink[selectedSpecies] + 1 << "\n";
                textString = textStringStream.str();
                app.draw(displayTextOnScreen(160,688,textString));
                textStringStream.str("");

                sf::Sprite temp;
                temp = allSprites[bringMeToLife_id];
                temp.setPosition(BMTL_x, BMTL_y);
                app.draw(temp);

            }
        }

        //6o)   if displayingConfirmChange == true,
        if(windowType == WT_displayingConfirmChange)
        {
            //6oI)  display "are you sure you wanna change dis 2 dis?" at (224, 656)
            app.draw(displayTextOnScreen(160,640,"Are you sure you want to change the original to this? (may result in creation of new species)"));
            app.draw(displayTextOnScreen(160,672,"Original:"));
            app.draw(displayTextOnScreen(544,672,"New:"));

            //6oIV) if the object being replaced is an action, display its sprite and the sprite of the new choice in the appropriate spots
            //for displaying original object, use x coordinate 208
            //for displaying choice, x = 592
            if(placeOneObject_isAction)
            {
                if(chartDisplaySprite[editObjectClicked] != -1)
                {
                    sf::Sprite original;
                    original = actions[chartDisplaySprite[editObjectClicked]];
                    original.setPosition(208,672);
                    app.draw(original);
                }

                sf::Sprite choice;
                choice = actions[placeOneObjectClicked];
                choice.setPosition(592,672);
                app.draw(choice);

                if(choiceRequiresData)
                {
                    std::cout << "choice requires data \n";
                    sf::Sprite choiceDataSprite;
                    choiceDataSprite = QAdata[choicesData];
                    choiceDataSprite.setPosition(656,680);
                    app.draw(choiceDataSprite);
                }
            }

            //6oV)  else, find the query sprite and do the same
            //for displaying new object, x = 592
            else
            {
                if(chartDisplaySprite[editObjectClicked] != -1)
                {
                    sf::Sprite original;
                    original = queries[chartDisplaySprite[editObjectClicked]];
                    original.setPosition(208,672);
                    app.draw(original);

                    sf::Sprite originalDestination;
                    originalDestination = destinations[destGivenChartDisplayNum(editObjectClicked, selectedSpecies)];
                    originalDestination.setPosition(208+chartBlockWidth,672);
                    app.draw(originalDestination);
                }

                sf::Sprite choice;
                std::cout << "chartDisplaySprite: " << chartDisplaySprite[placeOneObjectClicked] << "\n";
                choice = queries[chartDisplaySprite[placeOneObjectClicked]];
                choice.setPosition(592,672);
                app.draw(choice);

                sf::Sprite choiceDestination;
                choiceDestination = destinations[destinationSelected];
                choiceDestination.setPosition(592+chartBlockWidth,672);
                app.draw(choiceDestination);

                if(choiceRequiresData)
                {
                    std::cout << "choice requires data \n";
                    sf::Sprite choiceDataSprite;
                    choiceDataSprite = QAdata[choicesData];
                    choiceDataSprite.setPosition(656,672);
                    app.draw(choiceDataSprite);
                }
            }


        }


        //6p)   draw the sidemenu at the correct spot
        allSprites[sideMenu_id].setPosition(mapWidth*16, 0);
        app.draw(allSprites[sideMenu_id]);


        //6q)   if something has been clicked in edit mode...
        if(windowType == WT_editObjectSelected || windowType == WT_displayingConfirmChange || windowType == WT_selectingDestination)
        {
            //6qI)  draw the placeOne sprite at the specified spot
            placeOne.setPosition(mapWidth*16 + 8, 8);
            app.draw(placeOne);

            //6qII) if the value for the object that is clicked in ChartDisplaySprite array is greater than -1...
            if(chartDisplaySprite[editObjectClicked] > -1)
            {
                //6qII-1)   draws "currently in spot" sprite at the right position
                currentlyInSpot.setPosition(mapWidth*16 + 8, 160);
                app.draw(currentlyInSpot);

                //6qII-2)   if the editObjectClicked was an action, looks up sprite in actions array and displays under "currently in spot"
                if(editObjectClicked < 15) //implies that editObjectClicked was an action
                {
                    sf::Sprite thisGuy = actions[chartDisplaySprite[editObjectClicked]];
                    thisGuy.setPosition(mapWidth*16 + 8, 208);
                    app.draw(thisGuy);

                }
                //6qII-3)   else it's a query, do the same thing
                else
                {
                    sf::Sprite thisGuy = queries[chartDisplaySprite[editObjectClicked]];
                    thisGuy.setPosition(mapWidth*16 + 8, 208);
                    app.draw(thisGuy);
                }
            }

            //6qIII)    draws the "optionsToPlaceThere" sprite
            if(editObjectClicked < 60)
            {
                allSprites[optionsToPlaceThere_id].setPosition(mapWidth*16 + 8, optionsToPlaceThere_y);
                app.draw(allSprites[optionsToPlaceThere_id]);
            }


            //6qIV) creates a temp sprite
            sf::Sprite thisGuy;

            //6qV)  if the editObjectClicked is an action, draws all possible action choices below the "placeOneObject" sprite
            if(editObjectClicked < 15)
            {

                for(int i = 0; i < ACTION_greyedOut; i++)
                {
                    thisGuy = actions[i];
                    thisGuy.setPosition(beginPlaceOneOptionsX, beginPlaceOneOptionsY + 32*i);
                    app.draw(thisGuy);
                }
            }

            //6qVI) else (the editObjectClicked is a query) draws all the queries below the options header
            else if(editObjectClicked < 60) //this only happens as long as the query is not a default query
            {
                for(int i = 0; i < QUERY_default; i++)
                {
                    thisGuy = queries[i];
                    thisGuy.setPosition(beginPlaceOneOptionsX, beginPlaceOneOptionsY + 16*i);
                    app.draw(thisGuy);
                }
            }
        }

        //if you need to selectData - may need to change this later as it only applies to sounds rn
        else if(windowType == WT_selectingData)
        {
            sf::Sprite thisGuy;

            for(int i = 0; i < numDataChoices; i++)
            {
                thisGuy = QAdata[i];
                thisGuy.setPosition(QADataListX, QADataListY + i*16);
                app.draw(thisGuy);
            }

            thisGuy = selectSound;
            thisGuy.setPosition(800,0);
            app.draw(thisGuy);

        }

        //6r)   if editing, draws the "Select a spot to edit" text box
        else if(windowType == WT_editing)
        {
            selectASpot.setPosition(mapWidth*16 + 8, 8);
            app.draw(selectASpot);
        }

        //6s)   draws the yesNoBlock
        if(windowType == WT_displayingConfirmChange)
        {
            std::cout << "drawing the yesNoBlock\n";
            yesNoBlock.setPosition(yesNoBlockX,yesNoBlockY);
            app.draw(yesNoBlock);
        }

        //6t)   Update the display window with all the wonderful new things we have drawn
        app.display();

        //6u)   Totals all the energy in the game and saves it to totalEnergy (can probably be removed later on)
        int totalEnergy = 0;
        for(int n = 0; n < popSize; n++)
        {
            if(population[n].alive)
            {
                totalEnergy = totalEnergy + population[n].energy;
            }
        }
    }

    //7)    Saves the game
    save();

    //8)    final return value - program ends with SUCESS
    return EXIT_SUCCESS;
}

//#include "showIndividualInfo.h"
