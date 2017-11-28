#include "PatternSpotter.h"

Pattern::Pattern() {
}

void Pattern::SetPattern(int _w,int _h,bool _grid[][10]) {
  w = _w;
  h = _h;
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      grid[j][i] = _grid[j][i];
    }
  }
}
void Pattern::Print() {
  for (int i=0;i<h;i++) {
    for (int j=0;j<w;j++) {
      if (grid[j][i] == true) {
        cout << "▓ ";
      } else {
        cout << "░ ";
      }
    }
    cout << "\n\n";
  }
}
