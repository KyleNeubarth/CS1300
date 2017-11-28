#include "LifeAlgorithm.h"

LifeAlgorithm::LifeAlgorithm(int _w, int _h) {
  w=_w;
  h=_h;
  for (int i=0;i<w;i++) {
    for (int j=0;j<h;j++) {
      grid[i][j] = false;
    }
  }
}
LifeAlgorithm::LifeAlgorithm(int _w, int _h,bool _grid[][10]) {
  w=_w;
  h=_h;
  for (int i=0;i<w;i++) {
    for (int j=0;j<h;j++) {
      grid[i][j] = _grid[i][j];
    }
  }
}
void LifeAlgorithm::Seed() {
  srand(time(0)); 
  for (int i=0;i<w;i++) {
    for (int j=0;j<h;j++) {
      int random = rand()%3;
      if (random == 0) {
        grid[i][j]=true;
      } else {
        grid[i][j] = false;
      }
    }
  }
}
void LifeAlgorithm::SetWrapGrid(bool input) {
  wrapGrid = input;
}
void LifeAlgorithm::Draw() {
  system("clear");
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      if (grid[j][i]) {
        cout << "▓ ";
      } else {
        cout << "░ ";
      }
    }
    cout << "\n\n";
  }
}
void LifeAlgorithm::DoTick() {
  bool newGrid[w][h];
  for (int i=0;i<w;i++) {
    for (int j=0;j<h;j++) {
      int count = 0;
      if (Search(i,j+1)) {
        count++;
      }
      if (Search(i+1,j+1)) {
        count++;
      }
      if (Search(i+1,j)) {
        count++;
      }
      if (Search(i+1,j-1)) {
        count++;
      }
      if (Search(i,j-1)) {
        count++;
      }
      if (Search(i-1,j-1)) {
        count++;
      }
      if (Search(i-1,j)) {
        count++;
      }
      if (Search(i-1,j+1)) {
        count++;
      }
      //die from isolation
      if (grid[i][j] == true) {
        if (count < 2) {
          newGrid[i][j] = false;
        } else if (count > 1 && count < 4 && grid[i][j]) {
          newGrid[i][j] = true;
        //die from overpopulation
        } else {
          newGrid[i][j] = false;
        }
      } else {
        if (count == 3) {
          newGrid[i][j] = true;
        } else {
          newGrid[i][j] = false;
        }
      }
    }
  }
  for (int i=0;i<w;i++) {
    for (int j=0;j<h;j++) {
      grid[i][j] = newGrid[i][j];
    }
  }
}
bool LifeAlgorithm::Search(int x, int y) {
  if (x<0) {
    if (wrapGrid) {
      x=w-1;
    } else {
      return false;
    }
  } else if (x>w-1){
    if (wrapGrid) {
      x=0;
    } else {
      return false;
    }
  }
  if (y<0) {
    if (wrapGrid) {
      y=h-1;
    } else {
      return false;
    }
  } else if (y>h-1){
    if (wrapGrid) {
      y=0;
    } else {
      return false;
    }
  }
  return grid[x][y];
}