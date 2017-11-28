#include <iostream>
#include "LifeAlgorithm.h"
#include "PatternSpotter.h"
#include "Pattern.h"
#include <unistd.h>
using namespace std;

int main() {
  //LifeAlgorithm alg = LifeAlgorithm(20,20);
  LifeAlgorithm alg = LifeAlgorithm(24,10);
  alg.SetWrapGrid(true);
  PatternSpotter spot = PatternSpotter("SamplePattern.txt");
  //alg.Seed();
  spot.PastePattern(0,0,"block",alg.grid);
  spot.PastePattern(0,2,"block",alg.grid);
  spot.PastePattern(0,4,"block",alg.grid);
  spot.PastePattern(0,6,"block",alg.grid);
  spot.PastePattern(0,8,"block",alg.grid);
  spot.PastePattern(2,8,"block",alg.grid);
  spot.PastePattern(6,8,"block",alg.grid);
  spot.PastePattern(6,6,"block",alg.grid);
  spot.PastePattern(6,4,"block",alg.grid);
  spot.PastePattern(6,0,"block",alg.grid);
  spot.PastePattern(10,0,"block",alg.grid);
  spot.PastePattern(10,2,"block",alg.grid);
  spot.PastePattern(10,4,"block",alg.grid);
  spot.PastePattern(10,6,"block",alg.grid);
  spot.PastePattern(10,8,"block",alg.grid);
  spot.PastePattern(12,4,"block",alg.grid);
  spot.PastePattern(12,0,"block",alg.grid);
  spot.PastePattern(16,0,"block",alg.grid);
  spot.PastePattern(16,2,"block",alg.grid);
  spot.PastePattern(16,4,"block",alg.grid);
  spot.PastePattern(16,6,"block",alg.grid);
  spot.PastePattern(16,8,"block",alg.grid);
  spot.PastePattern(18,0,"block",alg.grid);
  spot.PastePattern(18,4,"block",alg.grid);
  spot.PastePattern(18,8,"block",alg.grid);
  spot.PastePattern(22,8,"block",alg.grid);
  spot.PastePattern(22,4,"block",alg.grid);
  spot.PastePattern(22,2,"block",alg.grid);
  spot.PastePattern(22,0,"block",alg.grid);
  //spot.PastePattern(5,0,1,alg.grid);
  alg.Draw();
  alg.DoTick();
  usleep(2000000);//unistd
  int frames = 0;
  
  while (frames < 105) {
    frames++;
    system("clear");
    alg.Draw();
    alg.DoTick();
    usleep(100000);
  }
  
  cout << "An Explanation of Conway's Game of Life\n A project for CSCI 1300 by Kyle Neubarth\n\nPress any button to continue!\n\n";
  cin.ignore();
  cout << "The Game of Life is a computer simulation made by british mathematician John Horton Conway.\n\n";
  cin.ignore();
  cout << "The game is based on a grid of cells, which are dead or alive, and are subject to these rules every tick:\n";
  cin.ignore();
  cout << "\r.A neighbor is a cell adjacent or diagonal to the current cell\n";
  cin.ignore();
  cout << "1.) A living cell with one or fewer neighbors will die, as if by isolation.\n";
  cin.ignore();
  cout << "\n░ ░ ░ \n\n░ ▓ ░ \n\n░ ░ ░\n\nThe middle cell will die because it has no neighbors\n";
  cin.ignore();
  cout << "\n░ ░ ░ \n\n░ ░ ░ \n\n░ ░ ░\n\n";
  cin.ignore();
  cout << "2.) A living cell with two or three neighbors will survive and continue living\n";
  cin.ignore();
  cout << "\n▓ ░ ▓ \n\n░ ▓ ░ \n\n░ ░ ░\n\nThe middle cell will live because it has supportive friends\n";
  cin.ignore();
  cout << "\n░ ░ ░ \n\n░ ▓ ░ \n\n░ ░ ░\n\n";
  cin.ignore();
  cout << "3.) A living cell with four or more neighbors dies, as if by overpopulation\n";
  cin.ignore();
  cout << "\n▓ ░ ▓ \n\n░ ▓ ░ \n\n▓ ░ ▓\n\nThe middle cell will die because it cannot handle the stress caused by so many neighbors\n(The neighbors also die because of isolation)\n";
  cin.ignore();
  cout << "\n░ ░ ░ \n\n░ ░ ░ \n\n░ ░ ░\n\n";
  cin.ignore();
  cout << "4.) A dead cell with exactly three neighbors turns into a living cell, as if by reproduction\n";
  cin.ignore();
  cout << "\n▓ ▓ ░ \n\n░ ░ ░ \n\n░ ▓ ░\n\nBoth the middle cell and the left middle cell become alive because conditions are right\n";
  cin.ignore();
  cout << "\n░ ░ ░ \n\n▓ ▓ ░ \n\n░ ░ ░\n\n";
  cin.ignore();
  
  cout << "And that's it! Based on a starting configuration of cells, Life will run like you saw in the intro.\nNow you may play around with the algorithm, by pressing any key and then enter you move forward a tick in time. When you are done, type \"done\".\nPress any key to start!";
  cin.ignore();
  cout << "Should the grid wrap? (will a cell at the edge of the map see cells on the other edge?) (y/n)\n";
  string theWrap;
  cin >> theWrap;
  LifeAlgorithm alg2 = LifeAlgorithm(15,10);
  alg2.Seed();
  if (theWrap == "y") {
    cout << "Wrap set to true\n\n";
    alg2.SetWrapGrid(true);
  } else if (theWrap == "n") {
    cout << "Wrap set to false\n\n";
    alg2.SetWrapGrid(false);
  } else {
    cout << "I didn't understand that, so wrap will be false anyway\n\n";
    alg2.SetWrapGrid(false);
  }
  usleep(2000000);
  bool running = true;
  while (running) {
    system("clear");
    alg2.Draw();
    alg2.DoTick();
    string in;
    cin >> in;
    if (in == "done") {
      running = false;
    }
  }
  cout << "Exiting simulation...\n\nYou may have noticed that Life tends to have an end. In the intro, the grid died and formed a stable pattern called a beehive:\n\n";
  spot.PrintPattern("beehive");
  cin.ignore();
  cout << "\nIf you look, you'll notice that every living cell has two or three neighbors, it is stable and will never change\n\nThese are called \'Still Lifes\', they will persist forever by themselves. Here is a list of still lifes:\n";
  cin.ignore();
  cout << "\nblock:\n";
  spot.PrintPattern("block");
  cin.ignore();
  cout << "\nbeehive:\n";
  spot.PrintPattern("beehive");
  cin.ignore();
  cout << "\nloaf:\n";
  spot.PrintPattern("loaf");
  cin.ignore();
  cout << "\nboat:\n";
  spot.PrintPattern("boat");
  cin.ignore();
  cout << "\ntub:\n";
  spot.PrintPattern("tub");
  cin.ignore();
  cout << "Now lets look at an oscilator in action:";
  cin.ignore();
  LifeAlgorithm alg4 = LifeAlgorithm(3,3);
  spot.PastePattern(0,0,"blinker",alg4.grid);
  frames = 0;
  while (frames < 20) {
    frames++;
    system("clear");
    alg4.Draw();
    alg4.DoTick();
    usleep(25000);
  }
  cout << "Oscilators are patterns which will repeat over and over forever. Some take longer to loop back over than others. Here are some single frames of oscilators:";
  cin.ignore();
  cout << "\nblinker:\n";
  spot.PrintPattern("blinker");
  cin.ignore();
  cout << "\ntoad:\n";
  spot.PrintPattern("toad");
  cin.ignore();
  cout << "\nbeacon:\n";
  spot.PrintPattern("beacon");
  cin.ignore();
  cout << "\n\nAnd finally, one of my favorites, I'll let this one run first before talking about it:";
  cin.ignore();
  LifeAlgorithm alg3 = LifeAlgorithm(10,15);
  alg3.SetWrapGrid(true);
  spot.PastePattern(0,0,"glider",alg3.grid);
  frames = 0;
  while (frames < 50) {
    frames++;
    system("clear");
    alg3.Draw();
    alg3.DoTick();
    usleep(25000);
  }
  cout << "That was the glider, a flying machine that will move across the grid forever until it meets an obstacle. Since the grip wraps it doesn't have to worry about walls! There are a lot of flying machines, but here are two of them:";
  cin.ignore();
  cout << "\nglider:\n";
  spot.PrintPattern("glider");
  cin.ignore();
  cout << "\nlightweightspaceship:\n";
  spot.PrintPattern("lightweightspaceship");
  cin.ignore();
  cout << "So, that was a quick summary or Conway's Game of Life and some common patterns that can be found in it. Just a quick poll for user satisfaction, do you think that my project could earn a grade of 90 or above?(y/n)\n";
  string put;
  cin >> put;
  if (put == "y") {
    cout << "Wow! that's really nice to hear!";
    alg2.SetWrapGrid(true);
  } else {
    cout << "Oh no! I'm sorry if there was something that was unsatisfactory. If it will make things any better, I can legitimately bake you homemade cookies or something. Send me an email at kyne7959@colorado.edu. I'm serious. I make really good cookies. Hit me up.";
  }
  cout << "\n\nEnd of project, I'm done with my presentation. Have a good day!";
}