#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sstream>
#include <string>

using namespace std;

auto additionQuestion(){
    int highLimit = 100;
    int lowLimit = 1;
    int x = rand() % (highLimit-lowLimit+1) + lowLimit;
    int y = rand() % (highLimit-lowLimit+1) + lowLimit;
    int z = x+y;
    struct question{int x; int y;int z;string oper;};
    return question{x,y,z,"+"};
}
auto subtractionQuestion(){
    int highLimit = 100;
    int lowLimit = 1;
    int x,y,z;
    bool properSet = false;
    while (properSet == false){
        x = rand() % (highLimit-lowLimit+1) + lowLimit;
        y = rand() % (highLimit-lowLimit+1) + lowLimit;
        z = x-y;
        if(z >= 0){
            properSet = true;
        }
    }

    struct question{int x; int y;int z;string oper;};
    return question{x,y,z,"-"};
}
auto multiplicationQuestion(){
    int highLimit = 10;
    int lowLimit = 2;
    int x = rand() % (highLimit-lowLimit+1) + lowLimit;
    int y = rand() % (highLimit-lowLimit+1) + lowLimit;
    int z = x*y;
    struct question{int x; int y;int z;string oper;};
    return question{x,y,z,"*"};
}
auto divisionQuestion(){
    int highLimit = 10;
    int lowLimit = 2;
    bool properSet = false;
    int x,y;
    while(properSet == false){
        x = rand() % (highLimit-lowLimit+1) + lowLimit;
        y = rand() % (highLimit-lowLimit+1) + lowLimit;
        int remainder = x % y;
        int quotient = x/y;
        if(remainder == 0 && quotient != 1){
            properSet = true;
        }
    }
    int z = x/y;
    struct question{int x; int y;int z;string oper;};
    return question{x,y,z,"/"};
}

auto mathQuestionGen(int difficil){
    int difficulty = difficil; //Will be used later to indicate question difficulty.
    srand(time(NULL));//Creating randomized seed based on time.
    int op = rand() % 4 + 1;//Choosing random operator for question. Not including division right now.

    //process variables
    stringstream q;
    int a;
    if(op == 1){//Subtraction.
        auto question = subtractionQuestion();
        q << "\nWhat is " << question.x << question.oper << question.y << "? ";
        a = question.z;
    }else if(op == 2){//Addition.
        auto question = additionQuestion();
        q << "\nWhat is " << question.x << question.oper << question.y << "? ";
        a = question.z;
    }else if(op == 3){//Multiplication.
        auto question = multiplicationQuestion();
        q << "\nWhat is " << question.x << question.oper << question.y << "? ";
        a = question.z;
    }else if(op == 4){//Division.
        auto question = divisionQuestion();
        q << "\nWhat is " << question.x << question.oper << question.y << "? ";
        a = question.z;
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