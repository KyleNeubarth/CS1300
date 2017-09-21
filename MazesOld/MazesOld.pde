float unitSize = width/8f;
float zoomSpeed = 0.01f;
float zoom = 1;
float xo,yo;

class cutSegment {
  float x;
  float y;
  float w;
  float h;
  public cutSegment(float _x, float _y, float _w, float _h) {
    x = _x;
    y = _y;
    h = _h;
    w = _w;
  }
}

ArrayList<cutSegment> cutList = new ArrayList<cutSegment>();
cutSegment list[] = new cutSegment[10];

void setup() {
  xo=width/2;
  yo=height/2;
  smooth();
  rectMode(CENTER);
  background(255);
  size(300,300);
  //Cut(0,175,300,125);
  Cut(0,0,width,height);
}
void draw() {
  translate(xo,yo);
  scale(zoom);
  zoom += zoomSpeed;
  rect(width>>1, height>>1, zoom, zoom);
}
void Cut(float x, float y, float w, float h) { 
  float divider;
  boolean dir; //true for horizontal, false for vertical
  //cut vertically
  if (w>h) {
    int cutX = 1 + floor(random(1)*(w/unitSize-1));
    divider = cutX*unitSize;
    dir = false;
    int holeY = floor(random(1)*(h/unitSize));
    line(x+cutX*(unitSize),y,x+cutX*(unitSize),y+(holeY)*unitSize);
    line(x+cutX*(unitSize),y+(holeY+1)*unitSize,x+cutX*(unitSize),y+h);
    //draw line x + (unitSize+1)
  //cut horizontally
  } else if(h>w) {
    int cutY = 1 + floor(random(1)*(h/unitSize-1));
    int holeX = floor(random(1)*(w/unitSize));
    divider = cutY*unitSize;
    dir = true;
    line(x,y+cutY*(unitSize),x+holeX*unitSize,y+cutY*(unitSize));
    line(x+(holeX+1)*unitSize,y+cutY*(unitSize),x+w,y+cutY*(unitSize));
  //pick random
  } else {
    if (random(1) >= .5f) {
      int cutX = 1 + floor(random(1)*(w/unitSize-1));
      int holeY = floor(random(1)*(h/unitSize));
      divider = cutX*unitSize;
      dir = false;
      line(x+cutX*(unitSize),y,x+cutX*(unitSize),y+holeY*unitSize);
      line(x+cutX*(unitSize),y+(holeY+1)*unitSize,x+cutX*(unitSize),y+h);
    } else {
      int cutY = 1 + floor(random(1)*(h/unitSize-1));
      int holeX = floor(random(1)*(w/unitSize));
      divider = cutY*unitSize;
      dir = true;
      line(x,y+cutY*(unitSize),x+holeX*unitSize,y+cutY*(unitSize));
      line(x+(holeX+1)*unitSize,y+cutY*(unitSize),x+w,y+cutY*(unitSize));
    }
  }
  //decide if new cells are big enough, then recurse
  if (!dir) {
    if (divider >= 2*unitSize) {
      Cut(x,y,divider,h);
    }
    if (w-divider >= 2*unitSize) {
      Cut(x+divider,y,w-divider,h);
    }
  } else {
    if (divider >= 2*unitSize) {
      Cut(x,y,w,divider);
    }
    if (h-divider >= 2*unitSize) {
      Cut(x,y+divider,w,h-divider);
    }
  }
}