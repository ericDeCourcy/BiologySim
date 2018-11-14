void moveMinerals ()
{
//    std::cout << "got into moveMinerals\n";
    for(int a = 0; a < mineralPopSize; a++)
    {
        if((mineralPop[a].directionMoving != -1) && (mineralPop[a].type != -1))
        {
            coordinates moveCoords = doMove(mineralPop[a].directionMoving, mineralPop[a].x, mineralPop[a].y);

            if((moveCoords.x != mineralPop[a].x) || (moveCoords.y != mineralPop[a].y))
            {
                gameMap[mineralPop[a].x][mineralPop[a].y] = MC_emptySpace;
                gameMap[moveCoords.x][moveCoords.y] = a + 1000;
                std::cout << "Setting gameMap[" << moveCoords.x << "][" << moveCoords.y << "] to " << a+1000 << "\n";

                mineralPop[a].x = moveCoords.x;
                mineralPop[a].y = moveCoords.y;
            }

            int stoppingRoll = rand()%100;  //returns a value 0 to 99

            if(stoppingRoll < mineralStoppingThresh)
            {
                mineralPop[a].directionMoving = -1;
            }
        }
    }
}


//doMove
