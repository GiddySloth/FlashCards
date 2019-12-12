#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <sstream>
#include "system\terminal.cpp"
#include "MathCard.cpp"
#include <windows.h>

using namespace std;
string version = "0.1a1";

auto questionGen(){
    auto question = mathQuestionGen(1);

    return question;
}

auto flashCardQuestions(){
    //Setting question parameters.
    int totalQuestions = 20;
    int correctQuestions = 0;
    
    for(int i = 0; i < totalQuestions; i++){
        //Creating a question.
        auto question = questionGen();

        //Asking the question.
        output(question.vraag);

        //Grabbing user input.
        int userAnswer = integerInput();

        //Checking if user is correct and scoring them.
        if(userAnswer == question.antwoord){
            correctQuestions++;
        }else if(userAnswer != question.antwoord){
            output(question.antwoordMessage);
        }
    }
    

    struct results {int tQ; int cQ;};
    return results {totalQuestions, correctQuestions};
}

void flashCardResult(int tQ, int cQ, double timeElapsed){
    //Creating the final result message.
    stringstream resultMessageS; 
    resultMessageS << "\nYou're score was " << cQ << "/" << tQ << ". You did it in " << timeElapsed << " seconds!";

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

    //Count-down
    countdown();

    //Start timer.
    auto startingTime = chrono::system_clock::now();

    //Starting FlashCard Sequence.
    auto results = flashCardQuestions();

    //Ending timer.
    auto endingTime = chrono::system_clock::now();
    double timeElapsed = double(chrono::duration_cast<chrono::milliseconds>(endingTime - startingTime).count()/1000);

    //Processing the result.
    flashCardResult(results.tQ, results.cQ, timeElapsed);

    //Ending program.
    return 0;
}


/*
This is a multi-line comment!
*/