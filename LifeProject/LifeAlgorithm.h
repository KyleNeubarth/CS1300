#ifndef LIFEALGORITHM_H
#define LIFEALGORITHM_H

#include <iostream>
#include <cstdlib>
using namespace std;

/*
  This class holds the grid, and can execute ticks forward in time
  Grid can be accessed through this class
*/

class LifeAlgorithm {
  public: 
  //initialize with new grid
    LifeAlgorithm(int,int);
    LifeAlgorithm(int,int,bool[][10]);
    void Draw();
    void Seed();
  //given a grid of boolean values, living or dead cells, do a tick, changing the grid according to the rules
    void DoTick();
    void SetWrapGrid(bool);
    // Get the current grid, used for drawing and looking for patterns
    //bool[][] GetGrid();
    //size of grid
    bool grid[100][100];
    int w;
    int h;
  private:
  //given a coordinate, return the state of that cell. Wraps if coord does not exist in grid. Used in DoTick.
    bool Search(int,int);
    
    //does the grid wrap?
    bool wrapGrid = false;
};

#endif