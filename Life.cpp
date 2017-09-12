#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int width;
int height;

int* pGrid;

bool inputType;

int Search(int x, int y) {
    if (x > width-1) {
        x -= width;
    }
    if (x < 0) {
        x += width;
    }
    if (y > height-1) {
        y -= height;
    }
    if (y < 0) {
        y += height;
    }
    return *(pGrid+x*height+y);
}

void DoTick() {

    int newGrid[width][height];
    for (int i=0;i<width;i++) {
        for (int j=0;j<height;j++) {
            newGrid[i][j] = 0;
        }
    }

    for (int i=0;i<width;i++) {
        for (int j=0;j<height;j++) {

            bool sides[] = {false,false,false,false,false,false,false,false};
            //up
            if (Search(i,j-1) == 1) {
                sides[0] = true;
            }
            //up,right
            if (Search(i+1,j-1) == 1) {
                sides[1] = true;
            }
            //right
            if (Search(i+1,j) == 1) {
                sides[2] = true;
            }
            //down,right
            if (Search(i+1,j+1) == 1) {
                sides[3] = true;
            }
            //down
            if (Search(i,j+1) == 1) {
                sides[4] = true;
            }
            //down,left
            if (Search(i-1,j+1) == 1) {
                sides[5] = true;
            }
            //left
            if (Search(i-1,j) == 1) {
                sides[6] = true;
            }
            //up,left
            if (Search(i-1,j-1) == 1) {
                sides[7] = true;
            }

            int num = 0;
            for (int k=0;k<8;k++) {
                if (sides[k]) {
                    num++;
                }
            }
            //if cell is living
            if (*(pGrid+i*height+j) == 1) {
                //cout << i <<""<<j<<": " << sides[0] << sides[1] << sides[2] << sides[3] << sides[4] << sides[5] << sides[6] << sides[7] << "\n";
                if (num >= 2 && num < 4) {
                    newGrid[i][j] = 1;
                }
            //if cell is dead
            } else {
                if (num == 3) {
                    newGrid[i][j] = 1;
                }
            }
        }
    }
    for (int i=0;i<width*height;i++) {
        *(pGrid+i) = *(newGrid[0]+i);
    }
}

void DrawGrid() {
    system("clear");
    for (int j=0;j<height;j++) {
        for (int i=0;i<width;i++) {

            if (*(pGrid+i*height+j) == 0) {
                cout << "░";
            } else {
                cout << "▓";
            }
            if (i == width-1) {
                cout << "\n";
            }
        }
    }
}

int RunLife() {
    cout << "Enter width of the grid:";
    cin >> width;
    cout << "Enter height of the grid:";
    cin >> height;

    if (width < 1) {
        width = 1;
    }
    if (height < 1) {
        height = 1;
    }

    char input;
    cout << "Type \"a\" for regular runTime or \"b\" to manually increment frames. Enter to increment\n";
    cin >> input;
    if (input == 'a') {
        inputType = true;
    } else if (input == 'b') {
        inputType = false;
    }

    int grid[width][height];
    pGrid = grid[0];
    for (int i=0;i<width;i++) {
        for (int j=0;j<height;j++) {
            grid[i][j] = rand() % 2;
        }
    }

    if (!inputType) {
        cin.ignore();
    }

    bool running = true;
    while (running) {
        DrawGrid();
        DoTick();
        if (!inputType) {
            cin.ignore();
        } else {
            usleep(500000);//unistd
        }
    }
    return 0;
}
