#ifndef EPISODE_H
#define EPISODE_H
#include <iostream>
#include "Video.h"
#include "Serie.h"

class Episode : public Video
{
    public:
        Episode(std::string, int, double, std::string, std::string, Serie*);
        ~Episode();
        virtual void print();
        int getNumEp();

    private:
        void setOwner(Serie*);
        void setNumEp(int);

    private:
        int numEp;
        Serie* owner;
};

#endif