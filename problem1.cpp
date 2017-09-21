#include <iostream>

using namespace std;

void menu(void);
void story1(void);
void story2(void);
void story3(void);

int main() {
    menu();
}

void menu(void) {
    bool running = true;
    while (running) {
        cout << "Which story would you like to play? Enter the number of the story (1, 2, or 3) or type q to quit: ";
        string input;
        cin >> input;
        if (input == "1") {
            story1();
        } else if (input == "2") {
            story2();
        } else if (input == "3") {
            story3();
        } else if (input == "q") {
            cout << "good bye";
            running = false;
        } else {
          cout << "Valid choice not selected.";
        }
    }
    return;
}

void story1(void) {
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
    
    cout << "In the book War of the "<<pluralNoun<<", the main character is an anonymous "<<occupation<<" who records the arrival of the "<<animal<<"s in "<<place<<".\n";
    return;
}
void story2(void) {
    string name;
    string stateCountry;
    
    cout << "Enter a name:\n";
    cin >> name;
    cout << "Enter a state/country:\n";
    cin >> stateCountry;
    cout << name << ", I've got a feeling we're not in " << stateCountry << " anymore.\n";
    return;
}
void story3(void) {
    string firstName;
    string relative;
    string verb;
    
    cout << "Enter a first name:\n";
    cin >> firstName;
    cout << "Enter a relative";
    cin >> relative;
    cout << "Enter a verb";
    cin >> verb;
    cout << "Hello. My name is "<<firstName<<". You killed my "<<relative<<".Perpare to "<<verb<<".\n";
    return;
}