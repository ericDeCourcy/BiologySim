ofstream logFile;

void spreadMinerals()
{
    mineralPop[0].directionMoving = -1;
    mineralPop[0].type = 0;
    mineralPop[0].x = 0;
    mineralPop[0].y = 3;
    gameMap[0][3] = 1000;

    mineralPop[1].directionMoving = -1;
    mineralPop[1].type = 0;
    mineralPop[1].x = 1;
    mineralPop[1].y = 3;
    gameMap[1][3] = 1001;

    mineralPop[2].directionMoving = -1;
    mineralPop[2].type = 0;
    mineralPop[2].x = 2;
    mineralPop[2].y = 3;
    gameMap[2][3] = 1002;

    mineralPop[3].directionMoving = -1;
    mineralPop[3].type = 0;
    mineralPop[3].x = 3;
    mineralPop[3].y = 3;
    gameMap[3][3] = 1003;

    mineralPop[4].directionMoving = -1;
    mineralPop[4].type = 0;
    mineralPop[4].x = 3;
    mineralPop[4].y = 0;
    gameMap[3][0] = 1004;

    mineralPop[5].directionMoving = -1;
    mineralPop[5].type = 0;
    mineralPop[5].x = 3;
    mineralPop[5].y = 1;
    gameMap[3][1] = 1005;

    mineralPop[6].directionMoving = -1;
    mineralPop[6].type = 0;
    mineralPop[6].x = 3;
    mineralPop[6].y = 2;
    gameMap[3][2] = 1006;

}

void closeLog()
{
    logFile.close();
}

void initializeLog()
{
    logFile.open("log.txt");
}

void coutAndLog(string content)
{
    logFile << content;
    std::cout << content;
}
