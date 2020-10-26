#ifndef MOVIE_H
#define MOVIE_Hname
#include "Video.h"

class Movie : public Video
{
    public:
    Movie(std::string, double, std::string, std::string);
    ~Movie();
    virtual void print();
};

#endif