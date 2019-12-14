#include <iostream>

using namespace std;

#ifndef TERMINAL_H
#define TERMINAL_H

void output(string message){
    cout << message;
}

int integerInput(){
    int input;
    cin >> input;
    return input;
}

#endif