#include "Rating.h"

Rating::Rating()
{
    setRtng();
    setNumVotes();
}

Rating::~Rating()
{

}

void Rating::setRtng()
{
    rtng = 0.0;
}

void Rating::setNumVotes()
{
    numVotes = 0;
}

double Rating::getRtng()
{
    return rtng;
}

int Rating::getNumVotes()
{
    return numVotes;
}

void Rating::operator +(int vote)
{
    double sum = (rtng * numVotes) + vote;

    numVotes++;
    rtng = sum / numVotes;
}
