void ProcessRow() {
  int start = (int)random(0,maze.get(maze.size()-1).length);
  int index = start;
  int dir = (random(0,1)<.5f)?1:-1;
  float boreChance = 0.1f;
  IntList active = new IntList();
  do {
   active.append(index);
    if (random(0,1)<boreChance) {
      //bore up,pick random from active set
      int rand = active.get((int)random(0,active.size()));
      maze.get(maze.size()-1)[rand].d = false;
      active = new IntList();
    } else {
      //move in dir
      if (dir == 1) {
        maze.get(maze.size()-1)[index].cl = false;
      } else {
        if (index + dir < 0) {
          maze.get(maze.size()-1)[maze.get(maze.size()-1).length-1].cl = false;
        } else {
          maze.get(maze.size()-1)[index-1].cl = false;
        }
      }
    }
    index += dir;
    if (index < 0) {
      index = maze.get(maze.size()-1).length-1;
    }
    if (index == maze.get(maze.size()-1).length) {
      index = 0;
    }
    
  } while (index!=start);
  active.append(index);
  int rand = active.get((int)random(0,active.size()));
  maze.get(maze.size()-1)[rand].d = false;
  maze.get(maze.size()-1)[start].cl = true;
}