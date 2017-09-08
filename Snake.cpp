#include <iostream>
#include <cstdlib> //system
#include <unistd.h>//sleep
#include <ncurses.h>//key input


using namespace std;

bool gameOver;

const int width = 20;
const int height = 20;
int x,y,fruitX,fruitY,score;

enum eDirection {STOP = 0, Left, Right, UP, DOWN};
eDirection dir;

void Setup() {
    system ("/bin/stty raw");
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % (width - 2);
    fruitY = rand() % (height - 2);
    fruitX++;
    fruitY++;
    score = 0;
}
void Draw() {
    system("clear");
    for (int i=0;i<width;i++) {
        cout << "#";
    }
    cout << "\n";

    for (int i=0;i<width;i++) {
        for (int j=0;j<height;j++) {
            if (i == x && j == y) {
                cout << "S";
            } else if (fruitX == i && fruitY == j) {
                cout << "F";
            } else if (j == 0) {
                cout << "#";
            } else if (j == width-1) {
                cout << "#\n";
            } else {
                cout <<"0";
            }
        }
    }

    for (int i=0;i<width;i++) {
        cout << "#";
    }
    cout << "\n";
}
void Input() {
}
void Logic() {
}
int main() {
    nodelay(stdscr, TRUE);
    if (getch() == ERR) {
        cout << "kkkkkk";
    }
    srand (time(NULL));
    Setup();
    /*while(!gameOver) {
        //if (GetKeyState()) {

        //}
        Draw();
        Input();
        Logic();
        usleep(1000);
        //gameOver = true;
    }*/
    return 0;
}
