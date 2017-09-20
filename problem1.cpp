#include <iostream>

using namespace std;

void story1();
void story2();
void story3();

void menu() {
    bool running = true;
    while (running) {
        cout << ""Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: ";
        string input;
        cin >> input;
        switch (input) {
            case "1":
                story1();
            break;
            case "2":
                story2();
            break;
            case "3":
                story3();
            break;
            case "q":
                cout << "good bye";
                running = false;
            break;
        }
    }
    return;
}

void story1() {
    string pluralNoun;
    string occupation;
    string animal;
    string place;
    
    cout << "Enter a plural noun:\n";
    cin >> pluralNoun;
    cout << "Enter an occupation:\n";
    cin >> occupation;
    cout << "Enter an animal:\n";
    cin >> animal;
    cout << "Enter a place:\n";
    cin >> place;
    
    cout << "In the book War of the "<<pluralNoun<<", the main character is an anonymous "<<ocupation<<" who records the arrival of the "<<animal<<"s in "<<place<<".";
    return;
}
void story2() {
    string name;
    string stateCountry;
    
    cout << "Enter a name:\n"
    cin >> name;
    cout << "Enter a state/country:\n"
    cin >> stateCountry;
    cout << name << ", I've got a feeling we're not in " << stateCountry << " anymore.";
    return;
}
void story3() {
    string firstName;
    string relative;
    string verb;
    
    cout << "Enter a first name:\n";
    cin >> firstName;
    cout << "Enter a relative";
    cin >> relative;
    cout << "Enter a verb";
    cin >> verb;
    cout << "Hello. My name is "<<firstName<<". You killed my "<<relative<<".Perpare to "<<verb<<".";
    return;
}