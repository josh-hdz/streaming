#include "Episode.h"

Episode::Episode(std::string id, int numEp, double time, std::string name, std::string genre, Serie* sri)
{
    setName(name);
    setGenre(genre);
    setId(id);
    setTime(time);
    setNumEp(numEp);
    setOwner(sri);

    sri->list.push_back(this);
}

Episode::~Episode()
{
     
}

void Episode::setOwner(Serie* sri)
{
    owner = sri;
}

void Episode::setNumEp(int numEp)
{
    this->numEp = numEp; 
}

void Episode::print()
{
    if(getNumVotes() == 0)
    {
        std::cout << std::endl;
        std::cout << owner->getName(); 
        std::cout << ": Ep. " << getNumEp(); 
        std::cout << "   \"";
        std::cout << getName();
        std::cout << '\"';
        std::cout << " (" << getId();
        std::cout << ") ";
        std::cout << getTime();
        std::cout << " minutes   ";
        std::cout << "Genre: ";
        std::cout << getGenre();
        std::cout << "       ";
        std::cout << getNumVotes();
        std::cout << " Reviews";
        std::cout << std::endl;
    }
    else
    {
        std::cout << std::endl;
        std::cout << owner->getName(); 
        std::cout << ": Ep. " << getNumEp(); 
        std::cout << "   \"";
        std::cout << getName();
        std::cout << '\"';
        std::cout << " (" << getId();
        std::cout << ") ";
        std::cout << getTime();
        std::cout << " minutes   ";
        std::cout << "Genre: ";
        std::cout << getGenre();
        std::cout << "       ";
        std::cout << getRate();
        std::cout << " Stars   ";
        std::cout << getNumVotes();
        std::cout << " Reviews";
        std::cout << std::endl;
    }
    
}

int Episode::getNumEp()
{
    return numEp;
}
