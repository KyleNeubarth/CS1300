#include <iostream>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int width;
int height;

int* pGrid;

void DoTick() {

    int newGrid[width][height];
    for (int i=0;i<width;i++) {
        for (int j=0;j<height;j++) {
            newGrid[i][j] = 0;
        }
    }

    for (int i=0;i<width;i++) {
        for (int j=0;j<height;j++) {

            bool sides[] = {false,false,false,false};
            //up
            if (j-1 > -1) {
                if (*(pGrid+i*height+j-1) == 1)  {
                sides[0] = true;
                }
            } else {
                if (*(pGrid+i*height+j-1+height) == 1)  {
                sides[0] = true;
                }
            }
            //right
            if (i+1 < width) {
                if (*(pGrid+(i+1)*height+j) == 1)  {
                sides[1] = true;
                }
            } else {
                if (*(pGrid+(i+1-width)*height+j) == 1)  {
                sides[1] = true;
                }
            }
            //down
            if (j+1 < height) {
                if (*(pGrid+i*height+j+1) == 1)  {
                sides[2] = true;
                }
            } else {
                if (*(pGrid+i*height+j+1-height) == 1)  {
                sides[0] = true;
                }
            }
            //left
            if (i-1 > -1) {
                if (*(pGrid+(i-1)*height+j) == 1)  {
                sides[3] = true;
                }
            } else {
                if (*(pGrid+(i-1+width)*height+j) == 1)  {
                sides[1] = true;
                }
            }

            int num = 0;
            for (int k=0;k<4;k++) {
                if (sides[k]) {
                    num++;
                }
            }
            //if cell is living
            if (*(pGrid+i*height+j) == 1) {
                if (num > 1 && num < 4) {
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
        //int * pNew = newGrid[0];
        *(pGrid+i) = *(newGrid[0]+i);
    }
}

void coordsToIndex(int x, int y) {

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
    cout << "■Enter width of the grid:";
    cin >> width;
    cout << "Enter height of the grid:";
    cin >> height;

    int grid[width][height];
    pGrid = grid[0];
    for (int i=0;i<width;i++) {
        for (int j=0;j<height;j++) {
            grid[i][j] = rand() % 2;
        }
    }
    /*grid[0][1] = 1;
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[width-1][0] = 1;
    grid[width-1][2] = 1;*/

    bool running = true;
    while (running) {
        DrawGrid();
        DoTick();
        cin.ignore();
        //usleep(1000);//unistd

    }

    return 0;
}
