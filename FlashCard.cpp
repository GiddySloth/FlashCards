#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include <unistd.h>
#include <string>
#include <sstream>
#include "system\terminal.cpp"

using namespace std;

int x,y,z,op;
int totalQuestions,correctQuestions,highLimit,lowLimit,userAnswer;


auto questionGen(int hL, int lL, int difficil){
    int difficulty = difficil; //Will be used later to indicate question difficulty.
    srand(time(NULL));//Creating randomized seed based on time.
    op = rand() % 3 + 1;//Choosing random operator for question. Not including division right now.

    //Limits but should actually be defined per operator.
    highLimit = hL;
    lowLimit = lL;

    //Random numbers to calculate with.
    x = rand() % (highLimit-lowLimit+1) + lowLimit;
    y = rand() % (highLimit-lowLimit+1) + lowLimit;
    stringstream q;
    int a = 0;
    if(op == 1){//Subtraction.
        z = x-y;
        q << "What is " << x << "-" << y << "? ";
        a = z;
    }else if(op == 2){//Addition.
        z = x+y;
        q << "What is " << x << "+" << y << "? ";
        a = z;
    }else if(op == 3){//Multiplication.
        if(lowLimit == 1){
            lowLimit = 2;
        }
        x = rand() % (highLimit-lowLimit+1) + lowLimit;
        y = rand() % (highLimit-lowLimit+1) + lowLimit;
        z = x*y;
        q << "What is " << x << "*" << y << "? ";
        a = z;
    }else if(op == 4){//Division.
        if(lowLimit == 1){
            lowLimit = 2;
        }
        x = rand() % (highLimit-lowLimit+1) + lowLimit;
        y = rand() % (highLimit-lowLimit+1) + lowLimit;
        z = x/y;
        q << "What is " << x << "/" << y << "? ";
        a = z;
    }

    //Question.
    string qu = q.str();

    //Answer message.
    stringstream answer;
    answer << "The answer is " << a << ".\n";
    string am = answer.str();

    //Returning the question along with answer and answer message for output.
    struct result {string vraag; int antwoord; string antwoordMessage;};
    return result {qu, a, am};
}

auto flashCardQuestions(){
    //Setting question parameters.
    totalQuestions = 20;
    correctQuestions = 0;
    
    for(int i = 0; i < totalQuestions; i++){
        //Creating a question.
        auto question = questionGen(10, 1, 1);

        //Asking the question.
        output(question.vraag);

        //Grabbing user input.
        int userAnswer = integerInput();

        //Checking if user is correct and scoring them.
        if(userAnswer == question.antwoord){
            correctQuestions++;
        }else if(userAnswer != z){
            output(question.antwoordMessage);
        }
    }
    

    struct results {int tQ; int cQ;};
    return results {totalQuestions, correctQuestions};
}

void flashCardResult(int tQ, int cQ, double timeElapsed){
    //Creating the final result message.
    stringstream resultMessageS; 
    resultMessageS << "You're score was " << correctQuestions << "/" << totalQuestions << ". You did it in " << timeElapsed << " seconds!";

    //Outputting the final result.
    output(resultMessageS.str());
}

int main()
{   
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