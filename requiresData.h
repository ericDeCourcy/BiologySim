
bool actionRequiresData(int action)
{
    switch (action)
    {
        case ACTION_makeNoise:
        return true;
        break;

        default:
        return false;
    }
}

bool queryRequiresData(int query)
{
    switch (query)
    {
        case QUERY_heardNoise:
        return true;
        break;

        default:
        return false;
    }
}
