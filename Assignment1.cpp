#include <iostream>
#include <math.h>

using namespace std;

int currentPop = 325766246;

int CalculatePop(int daysElapsed) {
    float secondsElapsed = daysElapsed * 24 * 60 * 60;
    long newPop = currentPop + secondsElapsed/8.0 - secondsElapsed/12.0 + secondsElapsed/33.0;

    return floor (newPop);
}

//used for robot hunt to turn the robot
int Turn(bool change, int dir) {
    if (change) {
        dir--;
        if (dir < 0) {
            dir+= 4;
        }
    } else {
        dir++;
        if (dir > 3) {
            dir-= 4;
        }
    }
}
void Move(int* pos, int dir) {
    if (dir == 0) {
        cout << "\n" << *(++pos);
        ++(*(++pos));//north
        cout << "\n" << *(++pos);
    } else if (dir == 1) {
        *(pos)++;//east
    } else if (dir == 2) {
        *(++pos)--;//south
    } else if (dir == 3) {
        *(pos)--;//west
    }

    return;
}

int main() {
    int days;
    cout << "1.) The current US population is " << currentPop;

    cout << "\nHow many days have passed?\n";
    cin >> days;
    cout << "after " << days << " days the population is now " << CalculatePop(days) << ", gee whiz!";

    int seconds;

    cout << "\n2.) Given a number of seconds, how many minutes, hours, and days have passed?\n" << "seconds:";
    cin >> seconds;
    cout << "The time is " << seconds/(24*60*60) << " days, " << (seconds/3600)%24 << " hours, " << (seconds/60)%60 << " minutes, and " << seconds%60 << " seconds";

    float degF;
    cout << "\n3.)Convert Fahrenheit to Celsius\n Degrees Fahrenheit:";
    cin >> degF;
    cout << degF << " degrees Fahrenheit is equal to " << (degF - 32.0f) * (5.0f/9.0f) << " degrees Celsius! Woot!";

    bool pass = false;
    cout << "\n4.)You have a simple task, enter a number between 1 and 10 and you may live, human.";
    while (pass == false) {
        int num;
        cout << "\nNumber:";
        cin >> num;
        if (num > 1 && num < 10) {
            pass = true;
            cout << "Wow, you're not as dumb as you look\n";
        } else {
            cout << "Insolent fool, you have failed me. However because I am feeling nice today I will allow you another try";
        }
    }

    int mileage;
    cout << "5.) What is the mileage on your automobile, underling?\nMileage:";
    cin >> mileage;
    if (mileage > 50) {
        cout << "Nice job";
    } else if (mileage > 25) {
        cout << "Not great, but okay";
    } else {
        cout << "So bad, so very, very bad";
    }

    string choice;
    cout << "\n6.)Play my adventure game!\nType a, b, or c to select";

    while (choice != "c") {
        cout << "\nWhat would you like to do now?\n";
        cout << "a.)Fight the villain\nb.)Save the citizen\nc.)Return to secret base\n";
        cin >> choice;
        if (choice == "a") {
            cout << "You Win!";
        } else if (choice == "b") {
            cout << "You saved the citizen";
        } else if (choice == "c") {
            cout << "Who will save the world?";
        } else {
            cout << "I didn't understand that!";
        }
    }
    cout << "You have finished the adventure game!";

    cout << "\n7.)Welcome to robot treasure hunt! Bob the bot will find the treasure, no matter what!\nPress any key to have bob start navigating!\n";
    cin.ignore();
    /*
    y - treasure
    1w - move forward
    2b - turn left then move
    3g - turn right then move
    4p - turn 180 then move twice
    5y - end
    */
    int pos [] = {0,0};
    int dir = 0;
    //0 = n 1 = e 2 = s 3 = w
    int maze [4][4] =
    {
        {1,5,4,1},
        {5,2,2,5},
        {3,1,1,3},
        {3,1,3,4}
    };

    while (maze[pos[0]][pos[1]] != 5) {

        switch (maze[pos[0]][pos[1]]) {
        case 5:
            cout << "Bob found the treasure! Game is over!";
            break;
        case 1:
            cout << "Bob stepped on a white tile, and moves forward";
            Move(pos,dir);
            break;
        case 2:
            cout << "Bob steps on a blue tile, turns left and moves forward";
            dir = Turn(false,dir);
            Move(pos,dir);
            break;
        case 3:
            dir = Turn(true,dir);
            cout << "Bob steps on a blue tile, turns right and moves forward";
            Move(pos,dir);
            break;
        case 4:
            cout << "Bob steps on a black tile, turns twice and moves forward twice";
            dir = Turn(false,dir);
            dir = Turn(false,dir);
            Move(pos,dir);
            Move(pos,dir);
            break;
        }
        cout << "\n" << pos[1] << pos[0];
        cin.ignore();
    }
}
