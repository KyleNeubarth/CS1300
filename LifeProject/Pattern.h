#ifndef PATTERN_H
#define PATTERN_H

#include <iostream>
#include <fstream>
using namespace std;

class Pattern {
  public:
    Pattern();
    void SetPattern(int,int,bool [][10]);
    void Print();
    int w;
    int h;
    bool grid[][10];
};
#endif