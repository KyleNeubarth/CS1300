void AddSurroundings(int[] coords) {
  maze[coords[0]][coords[1]].type = 2;
  maze[coords[0]][coords[1]].id = globalId;
  globalId++;
  //up
  if (coords[0] != maze.length-1) {
    int tempI = coords[1];
    if (maze[coords[0]+1].length != maze[coords[0]].length) {
      tempI *= 2;
      //we need to add a 2nd active cell
      activeCells.add(new int[] {coords[0]+1,tempI+1});
      maze[coords[0]+1][tempI+1].type = 1;
    }
    if (maze[coords[0]+1][tempI].type == 0) {
      activeCells.add(new int[] {coords[0]+1,tempI});
      maze[coords[0]+1][tempI].type = 1;
    }
  }
  //down
  if (coords[0] != 0) {
    int tempI = coords[1];
    if (maze[coords[0]-1].length != maze[coords[0]].length) {
      tempI /= 2;
      //coords[1] += round(random(0,1));
    }
    if (maze[coords[0]-1][tempI].type == 0) {
      activeCells.add(new int[] {coords[0]-1,tempI});
      maze[coords[0]-1][tempI].type = 1;
    }
  }
  //clockwise
  if (coords[1] == maze[coords[0]].length-1) {
    if (maze[coords[0]][0].type == 0) {
      activeCells.add(new int[] {coords[0],0});
      maze[coords[0]][0].type = 1;
    }
  } else {
    if (maze[coords[0]][coords[1]+1].type == 0) {
      activeCells.add(new int[] {coords[0],coords[1]+1});
      maze[coords[0]][coords[1]+1].type = 1;
    }
  }
  //counterclockwise
  if (coords[1] == 0) {
    if (maze[coords[0]][maze[coords[0]].length-1].type == 0) {
      activeCells.add(new int[] {coords[0],maze[coords[0]].length-1});
      maze[coords[0]][maze[coords[0]].length-1].type = 1;
    }
  } else {
    if (maze[coords[0]][coords[1]-1].type == 0) {
      activeCells.add(new int[] {coords[0],coords[1]-1});
      maze[coords[0]][coords[1]-1].type = 1;
    }
  }
}
void PickRandom(int[] coords) {
  ArrayList<int[]> directions = new ArrayList<int[]>();
  ArrayList<String> strings = new ArrayList<String>();
  //up
  if (coords[0] != maze.length-1) {
    int tempI = coords[1];
    if (maze[coords[0]+1].length != maze[coords[0]].length) {
      tempI *= 2;
      //we need to add a 2nd active cell
      if (maze[coords[0]+1][tempI+1].type == 2) {
        directions.add(new int[] {coords[0]+1,tempI+1});
        strings.add("up");
      }
    }
    if (maze[coords[0]+1][tempI].type == 2) {
      directions.add(new int[] {coords[0]+1,tempI});
      strings.add("up");
    }
  }
  //down
  if (coords[0] != 0) {
    int tempI = coords[1];
    if (maze[coords[0]-1].length != maze[coords[0]].length) {
      tempI /= 2;
    }
    if (maze[coords[0]-1][tempI].type == 2) {
      directions.add(new int[] {coords[0]-1,tempI});
      strings.add("down");
    }
  }
  //clockwise
  if (coords[1] == maze[coords[0]].length-1) {
    if (maze[coords[0]][0].type == 2) {
      directions.add(new int[] {coords[0],0});
      strings.add("cl");
    }
  } else {
    if (maze[coords[0]][coords[1]+1].type == 2) {
      directions.add(new int[] {coords[0],coords[1]+1});
      strings.add("cl");
    }
  }
  //counterclockwise
  if (coords[1] == 0) {
    if (maze[coords[0]][maze[coords[0]].length-1].type == 2) {
      directions.add(new int[] {coords[0],maze[coords[0]].length-1});
      strings.add("co");
    }
  } else {
    if (maze[coords[0]][coords[1]-1].type == 2) {
      directions.add(new int[] {coords[0],coords[1]-1});
      strings.add("co");
    }
  }
  if (directions.size()>0) {
    int chosen = (int) random(0,directions.size());
    /*if (strings.get(chosen)!="cl"&&strings.get(chosen)!="co") {
      chosen = (int) random(0,directions.size());
    }*/
    if (strings.get(chosen)=="up") {
      maze[directions.get(chosen)[0]][directions.get(chosen)[1]].d = false;
      maze[coords[0]][coords[1]].type = 2;
    } else if (strings.get(chosen)=="down") {
      maze[coords[0]][coords[1]].d = false;
    } else if (strings.get(chosen)== "cl") {
      maze[directions.get(chosen)[0]][directions.get(chosen)[1]].cl = false;
    } else if (strings.get(chosen)== "co") {
      maze[coords[0]][coords[1]].cl = false;
    }
  }
  maze[coords[0]][coords[1]].type = 2;
  maze[coords[0]][coords[1]].id = globalId;
  globalId++;
   
  AddSurroundings(new int[] {coords[0],coords[1]});
}