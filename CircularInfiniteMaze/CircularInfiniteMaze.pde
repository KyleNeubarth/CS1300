class Cell {
  //clockwise side, up, down
  public boolean cl,d = true;
  public int type = 0;
  public Cell(boolean cellType) {
    if (cellType) {
      cl = d = true;
      type = 0;
    } else {
      cl = d = false;
    }
  }
}

ArrayList<Cell[]> maze;
float time;
float timeUndo = 0;

float startTime = 1;
float timer = 1;

float z;

void setup() {
  maze = new ArrayList<Cell[]>();
  GenerateEmptyRow();
  size(600,600);
  background(255);
  z = 5000/pow(width/4,2);
}

void draw() {
  time = millis()/1000f - timeUndo;
  if (timer+startTime <= time) {
    GenerateRow();
    startTime = time;
  }
  
  
  DrawMaze();
}

void GenerateRow() {
  maze.add(new Cell[32]);
  for (int i=0;i<maze.get(maze.size()-1).length;i++) {
    maze.get(maze.size()-1)[i] = new Cell(true);
  }
  ProcessRow();
}
void GenerateEmptyRow() {
  maze.add(new Cell[32]);
  for (int i=0;i<maze.get(maze.size()-1).length;i++) {
    maze.get(maze.size()-1)[i] = new Cell(false);
  }
}

void DrawMaze() {
  
  background(255);
  translate(width/2,height/2);
  
  for (int i=0;i<maze.size();i++) {
    float w = (1/( constrain(.001f*(time-(i)-z),0,10000) ) );
    float w2 = (1/( constrain(.001f*(time-((i+1))-z),0,10000) ) );
    if (w < width/16) {
      maze.remove(i);
      timeUndo+=timer;
      startTime-=timer;
      time = millis()/1000f - timeUndo;
      w = (1/( constrain(.001f*(time-(i)-z),0,10000) ) );
      w2 = (1/( constrain(.001f*(time-((i+1))-z),0,10000) ) );
    }
    for (int h=0;h<maze.get(i).length;h++) {
      if (maze.get(i)[h].cl) {
        line(cos((float)h/maze.get(i).length*(PI*2))*w,sin((float)h/maze.get(i).length*(PI*2))*w,cos((float)h/maze.get(i).length*(PI*2))*w2,sin((float)h/maze.get(i).length*(PI*2))*w2);
      }
      if (maze.get(i)[h].d) {
        noFill();
        
        arc(0,0,w*2,w*2,(float)(h-1)/maze.get(i).length*(PI*2),(float)(h)/maze.get(i).length*(PI*2));
      }
    }
  }
  stroke(0);
  //arc(0,0,w*2*maze.size(),w*2*maze.size(),0,2*PI);
}