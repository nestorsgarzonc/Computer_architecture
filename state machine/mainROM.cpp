// WOKWI URL [https://wokwi.com/arduino/projects/314117365476360768]
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
    State nextState[7];
};

// ROM memory
memWord ROM[5];

void setup();

void loop();

int main() {
    setup();
    while (true)
        loop();
}

void setup() {
    ROM[0] = {"R, B", {S0, S0, S0, S1, S2, S3, S0}};
    ROM[1] = {"G, Y", {S1, S4, S1, S1, S1, S1, S1}};
    ROM[2] = {"G", {S2, S2, S2, S2, S2, S2, S4}};
    ROM[3] = {"Y", {S3, S3, S2, S3, S3, S3, S3}};
    ROM[4] = {"R, Y, G, B", {S0, S4, S4, S4, S4, S4, S4}};

    presentState = S0;
    output = ROM[presentState].output;

    cout << "Present State = " << presentState << " , "
         << "Output = " << output << endl;
}

void loop() {
    cout << "Input: ";
    cin >> input;
    /// States has the following range [1, 7]
    /// I do [input--] to start counting from zero, not from one
    input--;
    // next state selector (Multiplexer)
    nextState = ROM[presentState].nextState[input];
    presentState = nextState;
    output = ROM[presentState].output;
    cout << "Present State = " << presentState << " , "
         << "Output = " << output << endl;
}