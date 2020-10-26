#ifndef RATING_H
#define RATING_H

class Rating
{
    public:
        Rating();
        ~Rating();
        double getRtng();
        int getNumVotes();
        void operator +(int);

    private:
        void setRtng();
        void setNumVotes();

    private:
        double rtng;
        int numVotes;
};

#endif