#include <iostream>
#include <string>

using namespace std;

int input;
string output;

enum State {
    S0, S1, S2, S3, S4
};
State presentState, nextState;

struct memWord {
    string output;
    State nextState[4];
};

// ROM memory
memWord ROM[5];

void setup();

void loop();

int main() {
    setup();
    while (true)
        loop();
    return 0;
}

void setup() {
    ROM[0] = {"R", {S1, S0, S0, S0}};
    ROM[1] = {"Y", {S1, S2, S3, S1}};
    ROM[2] = {"G", {S2, S2, S2, S4}};
    ROM[3] = {"B", {S4, S3, S3, S3}};
    ROM[4] = {"G-Y", {S4, S4, S0, S4}};

    presentState = S0;
    output = ROM[presentState].output;

    cout << "Present State = " << presentState << " , "
         << "Output = " << output << endl;
}

void loop() {
    cout << "input? : ";
    cin >> input;

    // next state selector (Multiplexer)
    nextState = ROM[presentState].nextState[input];
    presentState = nextState;
    output = ROM[presentState].output;
    cout << "Present State = " << presentState << " , "
         << "Output = " << output << endl;
}