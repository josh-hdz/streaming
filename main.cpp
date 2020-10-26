#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Video.h"
#include "Movie.h"
#include "Episode.h"
#include "Serie.h"

using namespace std;

int main()
{
    vector<Video*> vdeo;
    vector<Serie*> sri;
    char cInp;

    do
    {
        cout << "--------------------------------------------------------------" << endl;
        cout << "|                              MENU                          |" << endl;
        cout << "|____________________________________________________________|" << endl;
        cout << "|                                                            |" << endl;
        cout << "| - Load file --------------------------------------->  'L'  |" << endl;
        cout << "|                                                            |" << endl;
        cout << "| - Print all videos -------------------------------->  'A'  |" << endl;
        cout << "|                                                            |" << endl;
        cout << "| - Print Videos (filter by genre) ------------------>  'V'  |" << endl;
        cout << "|                                                            |" << endl;
        cout << "| - Print Episodes (finter serie) ------------------->  'S'  |" << endl;
        cout << "|                                                            |" << endl;
        cout << "| - Print Videos (filter by rating) ----------------->  'B'  |" << endl;
        cout << "|                                                            |" << endl;
        cout << "| - Print Movies (filter by rating) ----------------->  'M'  |" << endl;
        cout << "|                                                            |" << endl;
        cout << "| - Rate a Video ------------------------------------>  'G'  |" << endl;
        cout << "|                                                            |" << endl;
        cout << "| - Delete all videos ------------------------------->  'D'  |" << endl;
        cout << "|                                                            |" << endl;
        cout << "| - Exit -------------------------------------------->  'E'  |" << endl;
        cout << "|                                                            |" << endl;
        cout << "--------------------------------------------------------------" << endl;

        cout << endl << "Select an option from the menu" << endl;
        cout << "..."; cin >> cInp;
        cout << endl;

        switch (cInp)
        {
            case 'L':
            case 'l': // Loads file.
            {
                ifstream file;
                string fileName,
                       dottxt = ".txt";

                cout << "File name: ";
                cin.clear();
                cin.ignore();
                getline(cin, fileName, '\n');
                cout <<  endl;

                int found = fileName.find(dottxt);

                // Adds ".txt" to file name if missing.
                if(found == string::npos)
                    fileName += dottxt;

                file.open(fileName);

                if(file.is_open())
                {
                    while(!file.eof())
                    {
                        string fInp;
                        getline(file, fInp, ',');
                        switch (fInp[0])
                        {
                            case 'C':
                            case 'c':
                            {
                                string  name,
                                        genre,
                                        tm,
                                        serieName,
                                        nmP,
                                    id;
                                int time,
                                    numEp;
                                bool found = false; 

                                //Reads inputs from files
                                getline(file, id, ',');
                                getline(file, name, ',');
                                getline(file, tm, ',');
                                getline(file, genre, ',');
                                getline(file, serieName, ',');
                                getline(file, nmP, '\n');
                                
                                //Convderts strings to ints
                                time = stoi(tm);
                                numEp = stoi(nmP);

                                // Creates serie if it doesnt exists alreaday
                                if(!sri.empty())
                                {
                                    for (auto sr : sri) // searches for a serie with same name
                                    {
                                        if(serieName == sr->getName())
                                        {
                                            found = true;
                                            break;
                                        }
                                    }
                                    if(!found)
                                        sri.push_back(new Serie(serieName));
                                    //else if found true it wonn't create new Serie Object.
                                }
                                else //if sri vector is empty
                                    sri.push_back(new Serie(serieName));

                                // reset found for next search.
                                found = false; 
                                    
                                //Creates Episode object linked to it's serie
                                // if it doent exist.
                                for (auto sr : sri)
                                {
                                    if(serieName == sr->getName())
                                    {
                                        // Checks for repeated Ep. in correspondent Serie
                                        for(auto ep : sr->list)
                                        {
                                            if(ep->getName() == name)
                                            {
                                                found = true;
                                                break;
                                            }
                                        }
                                        if(!found)
                                            vdeo.push_back(new Episode(id, numEp, time, name, genre, sr));
                                        // else it won't creaate a new Episode object
                                    }
                                }

                                break;
                            }

                            case 'P':
                            case 'p':
                            {
                                string name,
                                        genre,
                                        tm,
                                        id;
                                    double time;
                                    int numEp;
                                    bool found = false; 

                                    //Reads inputs from files
                                    getline(file, id, ',');
                                    getline(file, name, ',');
                                    getline(file, tm, ',');
                                    getline(file,genre,'\n');

                                    for(int i = 0; i < genre.size(); i++)
                                        if(genre[i] == '\r')
                                            genre.erase(i, 2);
                                    
                                    // Convderts strings to ints.
                                    time = stoi(tm);

                                    // Creates movie if it doen't exist.
                                    for(auto vp : vdeo)
                                    {
                                        if(vp->getName() == name)
                                        {
                                            found = true;
                                            break;
                                        }
                                    }
                                    if(!found)
                                        vdeo.push_back(new Movie(id, time, name, genre));
                                    // else it won't create a new Movie object.
                                
                                break;
                            }

                        default:
                            cout << "first letter in file line is not c or p" << endl << endl;
                            break;
                        }
                    }

                    cout << "File was load successfuly." << endl << endl;
                }
                else
                    cout << "File not found" << endl;

                file.close();

                break;
            } 
            
            case 'A':
            case 'a': // Prints all videos.
            {
                if(!vdeo.empty())
                    for(auto vp: vdeo)
                        vp->print();
                else
                    cout << "Database is empty" << endl;

                // Blank line before Menu pritns again.
                cout << endl; 
                break;
            }

            case 'V':
            case 'v': // Prints all video with specfic genre.
            {
                if(!vdeo.empty())
                {
                     string filter;
                    bool found = false;

                    cout << endl;
                    cout << "Genre: ";
                    cin.clear();
                    cin.ignore();
                    getline(cin, filter, '\n');
                    cout << endl;

                    for(auto vp: vdeo)
                    {
                        if(filter == vp->getGenre())
                        {
                            vp->print();
                            found = true;
                        }
                    }

                    if(!found)
                        cout << endl << "Videos was not found in database" << endl;
                }
                else
                    cout << "Database is empty" << endl;

                // Blank line before Menu pritns again.
                cout << endl; 
                break;
            }

            case 'S':
            case 's': // prints all Ep. from a serie.
            {
                if(!sri.empty())
                {
                    string filter;
                    bool found = false;

                    cout << endl;
                    cout << "Serie: ";
                    cin.clear();
                    cin.ignore();
                    getline(cin, filter, '\n');
                    cout << endl;

                    for(auto sr: sri)
                    {
                        if(filter == sr->getName())
                        {
                            found = true;
                            for(auto ep: sr->list)
                                ep->print();
                        }
                    }
                    if(!found)
                        cout << endl << "Serie does not exist in database" << endl;
                }
                else
                    cout << endl << "There is no series in the database" << endl;                

                // Blank line before Menu pritns again.
                cout << endl; 
                break;
            }

            case 'B':
            case 'b': // Prints all video with specfic rating.
            {
                if(!vdeo.empty())
                {
                    int filter;
                    bool found = false;

                    cout << endl;
                    cout << "Rating(1 - 5): "; cin >> filter;
                    while(filter < 1 || filter > 5)
                    {
                        cout << "Rating canot be less than 1 or higer than 5" << endl;
                        cout << endl;
                        cout << "Rating(1 - 5): "; cin >> filter;

                    }
                    cout << endl;

                    for(auto vp: vdeo)
                    {
                        if(vp->getRate() >= filter && vp->getRate() < filter + 1)
                        {
                            vp->print();
                            found = true;
                        }
                    }

                    if(!found)
                        cout << endl << "Videos with such rating was not found in database." << endl;
                }
                else
                    cout << "Database is empty" << endl;

                // Blank line before Menu pritns again.
                cout << endl; 
                break;
            }

            case 'M':
            case 'm': // Pritns all mvies with specific rating.
            {
                if(!vdeo.empty())
                {
                    int filter;
                    bool found = false;

                    cout << endl;
                    cout << "Rating(1 - 5): "; cin >> filter;

                    if(sri.empty())
                    {
                        if(!vdeo.empty())
                        {
                            for(auto vp : vdeo)
                            {
                                if(vp->getRate() >= filter && vp->getRate() < filter + 1)
                                {
                                    found = true;
                                    vp->print();
                                }
                            }
                            if(!found)
                                cout << endl << "Movie with such rating was not found in database" << endl;
                        }
                        else
                            cout << "Database is empty." << endl;
                    }
                    else
                    {
                        bool found2 = false; 

                        for(auto vp: vdeo)
                        {
                            found = false; // Rest found flag.
                            for(auto sr : sri)
                            {
                                for(auto ep: sr->list)
                                {
                                    if(vp->getName() == ep->getName())
                                    {
                                        found = true;

                                    }
                                }
                            }

                            if(!found && filter == vp->getRate())
                            {
                                found2 = true;
                                vp->print();
                            }
                        }

                        if(!found2)
                            cout << "No move with such rating was found in the database." << endl;
                    }
                }
                else
                    cout << "Database is empty." << endl;
                
                
                // Blank line before Menu pritns again.
                cout << endl; 
                break;
            }

            case 'G':
            case 'g': // Rates a video.
            {
                if(!vdeo.empty())
                {
                    string id;
                    int rate;
                    bool found = false;

                    cout << endl;
                    cout << endl << "Video ID: ";
                    cin.clear();
                    cin.ignore();
                    getline(cin, id, '\n');

                    for(auto vp: vdeo)
                    {
                        if(id == vp->getId())
                        {
                            cout << "Rate (1 - 5): ";
                            cin >> rate;
                            cout << endl;
                            found = true;
                            vp->update(rate);
                        }
                    }
                    if(!found)
                        cout << endl << "Video was not found in database" << endl;
                }
                else
                    cout << "Database empty" << endl;

                // Blank line before Menu pritns again.
                cout << endl; 
                break;
            }

            case 'D':
            case 'd': // erases all videos.
            {
                vdeo.clear();
                sri.clear();

                cout << endl << "Database was wiped succesfully." << endl;

                // Blank line before Menu pritns again.
                cout << endl; 
                break;
            }

            case 'E':
            case 'e':
                break;

            default:
                cout << endl << "Input not valid, try again." << endl;
                break;
        }

    }while(cInp != 'E' && cInp != 'e');
}