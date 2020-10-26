#include "Movie.h"

Movie::Movie(std::string id, double time, std::string name, std::string genre)
{
    setName(name);
    setGenre(genre);
    setId(id);
    setTime(time);
}

Movie::~Movie()
{

}

void Movie::print()
{
    if(getNumVotes() == 0)
    {
        std::cout << std::endl;
        std::cout << getName();
        std::cout << "(";
        std::cout << getId();
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
        std::cout << getName();
        std::cout << "(";
        std::cout << getId();
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