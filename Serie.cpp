#include "Serie.h"
#include <string>
#include <iostream>

Serie::Serie(std::string name)
{
    setName(name); 
}

Serie::~Serie()
{

}

void Serie::setName(std::string name)
{
    this->name = name;
}

std::string Serie::getName()
{
    return name;
}