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

float w = 0;
float targetW = 0;
float targetCY = 0;
float cx = w/2 + 300;
float cy = 0;

int eyeX = 0;
int eyeY = 0;

ArrayList<Cell[]> maze;
float time;
float timeUndo = 0;

float startTime = 1;
float timer = 0.5f;

float z;

void setup() {
  frameRate(60);
  maze = new ArrayList<Cell[]>();
  GenerateEmptyRow();
  size(600,600,P2D);
  background(255);
  z = 5000/pow(width/4,1.5f)*0.2f;
}

void draw() {
  
  background(255);
  translate(width/2,height/2);
  
  time = millis()/1000f - timeUndo;
  if (timer+startTime <= time) {
    GenerateRow();
    startTime = startTime + timer;
  }
  
  DrawMaze();
  
  cy = lerp(cy,targetCY,0.07f);
  w = lerp(w,targetW,0.09f);
  if (abs(cy-targetCY) < 1) {
    cy = targetCY;
  }
  noStroke();
  
  //pupil
  fill(30);
  stroke(1);
  ellipse(eyeX,eyeY,65,65);
  
  //iris
  float r = w/5f;
  stroke(3);
  noFill();
  ellipse(eyeX,eyeY,r*2.05f,r*2.05f);
  noStroke();
  fill(255);
  beginShape();
  vertex(0-width/2,0-height/2);
  vertex(0-width/2,eyeY);
  vertex(eyeX-w/2,eyeY);
  vertex(eyeX-r,eyeY);
  bezierVertex(eyeX-r,eyeY-(r*1.4f),eyeX+r,eyeY-(r*1.4f),eyeX+r,eyeY);
  vertex(width/2,eyeY);
  vertex(width/2,0-height/2);
  endShape();
  beginShape();
  vertex(0-width/2,0+height/2);
  vertex(0-width/2,eyeY);
  vertex(eyeX-w/2,eyeY);
  vertex(eyeX-r,eyeY);
  bezierVertex(eyeX-r,eyeY+(r*1.4f),eyeX+r,eyeY+(r*1.4f),eyeX+r,eyeY);
  vertex(width/2,eyeY);
  vertex(width/2,0+height/2);
  endShape();
  
  //eyelids
  fill(255);
  beginShape();
  vertex(0-width/2,0-height/2);
  vertex(0-width/2,eyeY);
  vertex(eyeX-w/2,eyeY);
  curveVertex(eyeX-cx,eyeY+cy);
  curveVertex(eyeX-w/2,eyeY);
  curveVertex(eyeX+w/2,eyeY);
  curveVertex(eyeX+cx,eyeY+cy);
  vertex(width/2,eyeY);
  vertex(width/2,0-height/2);
  endShape();
  beginShape();
  vertex(0-width/2,height);
  vertex(0-width/2,eyeY);
  vertex(eyeX-w/2,eyeY);
  curveVertex(eyeX-cx,eyeY-cy);
  curveVertex(eyeX-w/2,eyeY);
  curveVertex(eyeX+w/2,eyeY);
  curveVertex(eyeX+cx,eyeY-cy);
  vertex(width,eyeY);
  vertex(width,height);
  endShape();
  noFill();
  stroke(0);
  strokeWeight(5);
  curve(eyeX-cx,eyeY-cy,eyeX-w/2,eyeY,eyeX+w/2,eyeY,eyeX+cx,eyeY-cy);
  curve(eyeX-cx,eyeY+cy,eyeX-w/2,eyeY,eyeX+w/2,eyeY,eyeX+cx,eyeY+cy);
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
    strokeWeight(4);

  for (int i=0;i<maze.size();i++) {
    float mw = (1/( constrain(.01f*(time-(i*timer)-z),0,10000) ) );
    float mw2 = (1/( constrain(.01f*(time-((i+1)*timer)-z),0,10000) ) );
    if (mw < width/20 && maze.size()>1) {
      maze.remove(i);
      timeUndo+=timer;
      startTime-=timer;
      time = millis()/1000f - timeUndo;
      mw = (1/( constrain(.01f*(time-(i*timer)-z),0,10000) ) );
      mw2 = (1/( constrain(.01f*(time-((i+1)*timer)-z),0,10000) ) );
    }
    for (int h=0;h<maze.get(i).length;h++) {
      if (maze.get(i)[h].cl) {
        line(cos((float)h/maze.get(i).length*(PI*2))*mw,sin((float)h/maze.get(i).length*(PI*2))*mw,cos((float)h/maze.get(i).length*(PI*2))*mw2,sin((float)h/maze.get(i).length*(PI*2))*mw2);
      }
      if (maze.get(i)[h].d) {
        noFill();
        
        arc(0,0,mw*2,mw*2,(float)(h-1)/maze.get(i).length*(PI*2),(float)(h)/maze.get(i).length*(PI*2));
      }
    }
  }
  stroke(0);
}

void keyPressed() {
  if (keyCode == UP) {
    targetCY = targetW*1.7f;
  }
  if (keyCode == DOWN) {
    targetCY = 0;
  }
  if (keyCode == LEFT) {
    targetW = 400;
  }
}