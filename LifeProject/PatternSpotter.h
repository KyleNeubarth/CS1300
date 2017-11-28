#ifndef PATTERNSPOTTER_H
#define PATTERNSPOTTER_H

#include <iostream>
#include <fstream>
#include "Pattern.h"
using namespace std;

class PatternSpotter {
  public:
    //initializes, given file of patterns that are assigned to the arrays below.
    PatternSpotter(string);
    //paste a pattern onto the grid
    void PastePattern(int,int,string,bool[][100]);
    void PrintPattern(string);
    int numPatterns = 0;
    string patternNames[10];
    Pattern patterns[20];
};
#endif