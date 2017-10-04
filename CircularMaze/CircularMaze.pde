class Cell {
  //clockwise side, up, down
  public boolean cl,d = true;
  public int type = 0;
  public int id = 0;
  public Cell() {
    cl = d = true;
    type = 0;
  }
}

ArrayList<int[]> activeCells = new ArrayList<int[]>();
Cell maze[][];
int circles = 10;
int w;
int globalId = 0;
void setup() {
  size(600,600);
  w = width/circles/2;
  background(255);
  GenerateMaze(circles);
  PickRandom(activeCells.get(0));
  activeCells.remove(0);
}

void draw() {
  
  if (activeCells.size() > 0) {
    float rand = random(0,1);
    if (rand < 0.5f) {
      //pick newest
      PickRandom(activeCells.get(0));
      activeCells.remove(0);
  } else {
      //pick random
      int pick = (int)random(0,activeCells.size());
      PickRandom(activeCells.get(pick));
      activeCells.remove(pick);
    }
  DrawMaze();
  }
}

void GenerateMaze(int circles) {
  maze = new Cell[circles][];
  
  int num = 1;
  int j = 0;
  
  int totalLength = 0;
  
  for (int i=0;i<circles;i++) {
    if (j>=num) {
      num *=2;
      j=0;
    }
    j++;
    
    totalLength += num*8;
    maze[i] = new Cell[num*8];
    for (int h=0;h<maze[i].length;h++) {
      maze[i][h]=new Cell();
    }
  }
  
  //get random point
  int wormC = 0;
  int wormI = 0;
  
  int rand = (int) random(0,totalLength);
  for (int i=0;i<maze.length;i++) {
    if (rand < maze[i].length) {
      wormC = i;
      wormI = rand;
      break;
    }
    rand-=maze[i].length;
  }
  
  AddSurroundings(new int[] {wormC,wormI});
  
}
void DrawMaze() {
  
  background(255);
  translate(width/2,height/2);
  
  for (int i=0;i<maze.length;i++) {
    for (int h=0;h<maze[i].length;h++) {
      if (maze[i][h].cl) {
        if (maze[i][h].type==1) {
          stroke(244,80,60);
        } else if (maze[i][h].type==2) {
          stroke(0);
        } else {
          stroke(200);
        }
        line(cos((float)h/maze[i].length*(PI*2))*w*i,sin((float)h/maze[i].length*(PI*2))*w*i,cos((float)h/maze[i].length*(PI*2))*w*(i+1),sin((float)h/maze[i].length*(PI*2))*w*(i+1));
      }
      if (maze[i][h].d) {
        if (maze[i][h].type==1) {
          stroke(244,80,60);
        } else if (maze[i][h].type==2) {
          stroke(0);
        }else {
          stroke(200);
        }
        noFill();
        arc(0,0,w*(i)*2,w*(i)*2,(float)h/maze[i].length*(PI*2),(float)(h+1f)/maze[i].length*(PI*2));
      }
    }
  }
  stroke(0);
  arc(0,0,w*2*maze.length,w*2*maze.length,0,2*PI);
}