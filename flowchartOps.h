
//this function gives a numerical value for the destination given the ChartDisplayObject index of something
int destGivenChartDisplayNum(int chartDisplayNum, int whichSpecies)
{
    if(chartDisplayNum < 15)
    {
        return -1;
    }
    else if(chartDisplayNum < 30)
    {
        return flowcharts[whichSpecies][chartDisplayNum - 15].destination_A;
    }
    else if(chartDisplayNum < 45)
    {
        return flowcharts[whichSpecies][chartDisplayNum - 30].destination_B;
    }
    else if(chartDisplayNum < 60)
    {
        return flowcharts[whichSpecies][chartDisplayNum - 45].destination_C;
    }
    else if(chartDisplayNum < 75)
    {
        return flowcharts[whichSpecies][chartDisplayNum - 60].destination_default;
    }
}
