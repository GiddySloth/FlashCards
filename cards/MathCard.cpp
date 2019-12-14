#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <sstream>
#include <string>
#include <cmath>
#include "../system\userdata.h"

using namespace std;
double calculateMathExperience();

auto additionQuestion(int level){
    int highLimit, lowLimit, x, y, z;
    if(level == 1){
        highLimit = 10;
        lowLimit = 1;
    }else if(level == 2){
        highLimit = 25;
        lowLimit = 5;
    }else if(level == 3){
        highLimit = 50;
        lowLimit = 5;
    }else if(level == 4){
        highLimit = 100;
        lowLimit = 10;
    }else if(level == 5){
        highLimit = 200;
        lowLimit = 20;
    }
    
    x = rand() % (highLimit-lowLimit+1) + lowLimit;
    y = rand() % (highLimit-lowLimit+1) + lowLimit;
    z = x+y;
    struct question{int x; int y;int z;string oper;};
    return question{x,y,z,"+"};
}
auto subtractionQuestion(int level){
    int highLimit, lowLimit, x, y, z;
    if(level == 1){
        highLimit = 10;
        lowLimit = 1;
    }else if(level == 2){
        highLimit = 25;
        lowLimit = 5;
    }else if(level == 3){
        highLimit = 50;
        lowLimit = 5;
    }else if(level == 4){
        highLimit = 100;
        lowLimit = 10;
    }else if(level == 5){
        highLimit = 200;
        lowLimit = 20;
    }
    bool properSet = false;
    while (properSet == false){
        x = rand() % (highLimit-lowLimit+1) + lowLimit;
        y = rand() % (highLimit-lowLimit+1) + lowLimit;
        z = x-y;
        if(z > 0){
            properSet = true;
        }
    }

    struct question{int x; int y;int z;string oper;};
    return question{x,y,z,"-"};
}
auto multiplicationQuestion(int level){
    int highLimit, lowLimit, x, y, z;
    if(level == 1){
        highLimit = 5;
        lowLimit = 2;
    }else if(level == 2){
        highLimit = 10;
        lowLimit = 2;
    }else if(level == 3){
        highLimit = 15;
        lowLimit = 2;
    }else if(level == 4){
        highLimit = 20;
        lowLimit = 2;
    }else if(level == 5){
        highLimit = 25;
        lowLimit = 2;
    }

    x = rand() % (highLimit-lowLimit+1) + lowLimit;
    y = rand() % (highLimit-lowLimit+1) + lowLimit;
    z = x*y;
    struct question{int x; int y;int z;string oper;};
    return question{x,y,z,"*"};
}
auto divisionQuestion(int level){
    int highLimit, lowLimit, x, y, z;
    if(level == 1){
        highLimit = 10;
        lowLimit = 2;
    }else if(level == 2){
        highLimit = 25;
        lowLimit = 2;
    }else if(level == 3){
        highLimit = 50;
        lowLimit = 2;
    }else if(level == 4){
        highLimit = 100;
        lowLimit = 2;
    }else if(level == 5){
        highLimit = 200;
        lowLimit = 2;
    }

    bool properSet = false;
    while(properSet == false){
        x = rand() % (highLimit-lowLimit+1) + lowLimit;
        y = rand() % (highLimit-lowLimit+1) + lowLimit;
        int remainder = x % y;
        int quotient = x/y;
        if(remainder == 0 && quotient != 1){
            properSet = true;
        }
    }
    z = x/y;
    struct question{int x; int y;int z;string oper;};
    return question{x,y,z,"/"};
}

double calculateMathExperience(int userLevel){
    double experience = 1*pow(1.5, userLevel-1);
    return experience;
}

auto mathQuestionGen(user user1){
    srand(time(NULL));//Creating randomized seed based on time.
    int UML = user1.getLevel("Math"); //User Math level
    double experience = calculateMathExperience(UML);

    int op = rand() % 4 + 1;//Choosing random operator for question. Not including division right now.
    //process variables
    stringstream q;
    int a;
    if(op == 1){//Subtraction.
        auto question = subtractionQuestion(UML);
        q << "\nWhat is " << question.x << question.oper << question.y << "? ";
        a = question.z;
    }else if(op == 2){//Addition.
        auto question = additionQuestion(UML);
        q << "\nWhat is " << question.x << question.oper << question.y << "? ";
        a = question.z;
    }else if(op == 3){//Multiplication.
        auto question = multiplicationQuestion(UML);
        q << "\nWhat is " << question.x << question.oper << question.y << "? ";
        a = question.z;
    }else if(op == 4){//Division.
        auto question = divisionQuestion(UML);
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
    struct result {string vraag; int antwoord; string antwoordMessage; string category; double xp;};
    return result {qu, a, am, "Math", experience};
}