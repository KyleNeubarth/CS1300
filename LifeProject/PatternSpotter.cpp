#include "PatternSpotter.h"

PatternSpotter::PatternSpotter(string fileName) {
  ifstream file;
  file.open(fileName);
  if (!file.is_open()) {
    cout << "Could not open file!\n\n";
    return;
  }
  cout << "opened file\n\n";
  
  string temp;
  string tempName;
  //placeholder that is being written on, will be written onto a pattern and then reused
  bool newPattern[10][10];
  int w;
  int h = 0;
  int patternNum = 0;
  while (getline(file,temp)) {
    //end of pattern
    //cout << temp.length()<<";"<<h<<";";
    
    if (temp[0] == '/'&&temp[1] == '/') {
      tempName = temp.substr(2,temp.length()-2);
      continue;
    }
    //I found the end of a pattern!
    if (temp[0] == 'k') {
      if (h>0) {
        //cout << ";"<<w<<";"<<h<< ";" << patternNum <<";\n\n";
        
        patterns[patternNum].SetPattern(w,h,newPattern);
        if (tempName != "") {
          patternNames[patternNum] = tempName;
          tempName = "";
        }
        patternNum++;
        //increment total patterns
        numPatterns++;
        //debug code
        /*for (int i = 0;i<patternNum;i++) {
          patterns[i].Print();
          cout << "\n";
        }*/
      }
      w=0;
      h=0;
      //don't try and decipher this line, it has nothing in it
      continue;
    }
    w = temp.length();
    h++;
    //convert symbols to bools
    for (int i=0;i<temp.length();i++) {
      if (temp[i] == '#') {
        newPattern[i][h-1] = true;
        //cout << "▓ ";
      }else if (temp[i] == '0') {
        newPattern[i][h-1] = false;
        //cout << "░ ";
      }
    }
    //cout << "\n\n";
  }
}
void PatternSpotter::PastePattern(int x, int y, string name,bool theGrid[][100]) {
  int index = -1;
  for (int i=0;i<numPatterns;i++) {
    if (name == patternNames[i]) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    return;
  }
  for (int i=0;i<patterns[index].h;i++) {
    for (int j=0;j<patterns[index].w;j++) {
      theGrid[x+j][y+i] = patterns[index].grid[j][i];
    }
  }
}
void PatternSpotter::PrintPattern(string name) {
  int index = -1;
  for (int i=0;i<numPatterns;i++) {
    if (name == patternNames[i]) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    return;
  }
  patterns[index].Print();
}