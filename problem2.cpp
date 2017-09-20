#include <iostream>
#include <math.h> 

using namespace std;

float windChillCalculator(float airTemp, float wSpeed){
    return 35.74f+.6215f*airTemp-35.75f*pow(wSpeed,.16f)+.4275f*airTemp*pow(wSpeed,.16f);
}

void printWindChill(float airTemp,float lowWSpeed,float highWSpeed,float increment) {
    for (int i = lowWSpeed;i<highWSpeed;i+=increment) {
        cout << "The wind chill is " << windChillCalculator(airTemp,i) << " degrees F for an air temperature of " << airTemp << " degrees F" << " and a wind speed of " << i << " mph." << endl;
    }
}

int main() {
    float airTemp;
    float wSpeed;
    cout << "Enter air temperature:";
    cin >> airTemp;
    cout << "\nEnter wind speed:";
    cin >> wSpeed;
    cout << "\n";
    windChillCalculator(airTemp,wSpeed);
}