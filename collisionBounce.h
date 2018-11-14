
//if and ONLY IF something (the collider) collides with a MINERAL, that mineral will bounce
void collisionBounceHandler(int colliderX, int colliderY, int direction)
{
    int collisionObjectX = colliderX;
    int collisionObjectY = colliderY;

    if(direction == DIR_NE || direction == DIR_E || direction == DIR_SE)
    {
        collisionObjectX++;
    }
    else if(direction == DIR_NW || direction == DIR_W || direction == DIR_SW)
    {
        collisionObjectX--;
    }

    if(direction == DIR_SW || direction == DIR_S || direction == DIR_SE)
    {
        collisionObjectY++;
    }
    else if(direction == DIR_NW || direction == DIR_N || direction == DIR_NE)
    {
        collisionObjectY--;
    }

    int collisionObjectID = gameMap[collisionObjectX][collisionObjectY];

    if(collisionObjectID >= 1000)
    {
        mineralPop[collisionObjectID - 1000].directionMoving = direction;
    }
}
