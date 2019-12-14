#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <sstream>
#include "system\terminal.h"
#include "cards\MathCard.cpp"
#include <windows.h>
#include "system\userdata.h"

using namespace std;
user user1;
string version = "0.2a1";

auto questionGen(string questionCategory, user user1){
    auto question = mathQuestionGen(user1);

    return question;
}

auto flashCardQuestions(user user1){
    //Setting question parameters.
    int totalQuestions = 25;
    int correctQuestions = 0;
    
    for(int i = 0; i < totalQuestions; i++){
        //Creating a question.
        auto question = questionGen("Math", user1);

        //Asking the question.
        output(question.vraag);

        //Start timer.
        auto startingTime = chrono::system_clock::now();

        //Grabbing user input.
        int userAnswer = integerInput();

        //Ending timer.
        auto endingTime = chrono::system_clock::now();
        double timeElapsed = double(chrono::duration_cast<chrono::milliseconds>(endingTime - startingTime).count()/1000);

        //Checking if user is correct and scoring them.
        if(userAnswer == question.antwoord){
            correctQuestions++;
            user1.processExperience(question.xp, question.category);
            user1.checkUpgrade(question.category);
        }else if(userAnswer != question.antwoord){
            output(question.antwoordMessage);
        }
    }
    

    struct results {int tQ; int cQ;};
    return results {totalQuestions, correctQuestions};
}

void flashCardResult(int tQ, int cQ){
    //Creating the final result message.
    stringstream resultMessageS; 
    resultMessageS << "\nYou're score was " << cQ << "/" << tQ << "."; //Mention how much XP was gained at the end of a round!

    //Outputting the final result.
    output(resultMessageS.str());
}

void countdown(){
    int time = 3;
    while (time >= 1){
        stringstream timeLeft;
        timeLeft << time << "\n";
        output(timeLeft.str());
        time--;
        Sleep(1000);
    }
    output("START!\n");
}

int main()
{   
    //Welcome message.
    stringstream welcomeMessage;
    welcomeMessage << "Welcome to Flashcards v" << version << "!\n\n";
    output(welcomeMessage.str());

    //declare user
    user1.createUser();

    //Count-down
    countdown();

    //Starting FlashCard Sequence.
    auto results = flashCardQuestions(user1);

    //Processing the result.
    flashCardResult(results.tQ, results.cQ);

    //Ending program.
    return 0;
}


/*
This is a multi-line comment!
*/