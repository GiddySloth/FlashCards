#include <iostream>
#include "terminal.h"
#include <sstream>

using namespace std;

#ifndef USERDATA_H
#define USERDATA_H

class user{
    public:

    double mathUserExperience;
    int mathUserLevel;
    int mathLevelSystem [5];

    void createUser(){
        mathUserExperience = 0;
        mathUserLevel = 1;
        mathLevelSystem [0] = 20;
        mathLevelSystem [1] = 40;
        mathLevelSystem [2] = 80;
        mathLevelSystem [3] = 160;
        mathLevelSystem [4] = 320;
    }

    void processExperience(double experience, string category){
        if(category == "Math"){
            mathUserExperience = mathUserExperience + experience;
            //cout << "XP ADDED, NEW XP: " << mathUserExperience; 
        }
    }
    void checkUpgrade(string category){
        if(category == "Math"){
            for(int i = 0; i < 5; i++){
            if(i == 0){
                if(mathUserExperience < mathLevelSystem[i]){
                    mathUserLevel = 1;
                    break;
                }
            }else if(i == 4){
                if(mathUserExperience >= mathLevelSystem[i]){
                    if(mathUserLevel != 5){
                        stringstream levelUp;
                        levelUp << "\nYou've reached Math Level " << mathUserLevel << "!\n";
                        output(levelUp.str());
                    }
                    mathUserLevel = 5;
                    break;
                }
            }else{
                if(mathUserExperience >= mathLevelSystem[i-1] && mathUserExperience < mathLevelSystem[i]){
                    if(mathUserLevel != i+1){
                        stringstream levelUp;
                        levelUp << "\nYou've reached Math Level " << mathUserLevel+1 << "!\n";
                        output(levelUp.str());
                    }
                    mathUserLevel = i+1;
                    break;
                    }
                }
            }
        }
    }

    int getLevel(string category){
        if(category == "Math"){
            return mathUserLevel;
        } else {
            return 0;
        }
    }

};

#endif