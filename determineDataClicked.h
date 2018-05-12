int determineDataClicked(int y)
{
    int relativeY = y - QADataListY;
    int postDiv = (relativeY / 16);
    return postDiv;
}
