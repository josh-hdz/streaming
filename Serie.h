#ifndef SERIE_H
#define SERIE_H
#include <string>
#include <vector>
#include "Video.h"

class Serie
{
    public:
        Serie(std::string);
        ~Serie();
        std::string getName();

    private:
        void setName(std::string);

    private:
        std::string name;
        
    //If not defined public circular referencing needed
    public:
        std::vector<Video*> list;
};

#endif