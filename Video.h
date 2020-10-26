#ifndef VIDEO_H
#define VIDEO_H
#include <string>
#include <iostream>
#include "Rating.h"

class Video
{
    public:
    Video();
    ~Video();
    void update(int);
    virtual void print() = 0;
    std::string getName();
    std::string getGenre();
    std::string getId();
    double getTime();
    double getRate();
    int getNumVotes();
    
    protected:
        void setName(std::string);
        void setGenre(std::string);
        void setId(std::string);
        void setTime(double);

    protected:
        std::string id,
                    name,
                    genre;
        double time;
        Rating rate;
};

#endif
