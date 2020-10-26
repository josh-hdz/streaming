#include <iostream>
#include "Video.h"

Video::Video()
{

}

Video::~Video()
{
    
}

void Video::setName(std::string name)
{
    this->name = name;
}

void Video::setGenre(std::string genre)
{
    this->genre = genre;
}

void Video::setTime(double time)
{
    if(time > 0)
        this->time = time;
    else
        std::cout << "Time input has to be more than 0" << std::endl;
}

void Video::setId(std::string id)
{
    this->id = id;
}

void Video::update(int vote)
{
    rate + vote;
}

std::string Video::getName()
{
    return name;
}

std::string Video::getGenre()
{
    return genre;
}

std::string Video::getId()
{
    return id;
}

double Video::getTime()
{
    return time;
}

double Video::getRate()
{
    return rate.getRtng();
}

int Video::getNumVotes()
{
    return rate.getNumVotes();
}