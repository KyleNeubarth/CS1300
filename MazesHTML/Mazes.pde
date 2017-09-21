float unitSize;
float zoom = 1;
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
  boolean isBigEnough() {
    if (h >= 2*unitSize && w >= 2*unitSize) {
      return true;
    } else {
      return false;
    }
  }
}

ArrayList<cutSegment> cutList = new ArrayList<cutSegment>();

void setup() {
  background(255);
  size(600,600);
  unitSize = width/16f;
  //Cut(0,175,300,125);
  //Cut(0,0,width,height);
  cutList.add(new cutSegment(0,0,width,height));
}
void draw() {
  zoom+=0.001f;
  //scale(zoom);
  boolean succeed = false;
  int index = 0;
  while(!succeed && cutList.size() > 0) {
    if (cutList.get(index).isBigEnough()) {
      Cut(cutList.get(index).x,cutList.get(index).y,cutList.get(index).w,cutList.get(index).h);
      cutList.remove(0);
      succeed = true;
    }
    index++;
    if (index >= cutList.size()) {
      unitSize = unitSize/2f;
      succeed = true;
    }
  }
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
      cutList.add(1,new cutSegment(x,y,divider,h));
    } else {
      cutList.add(new cutSegment(x,y,divider,h));
    }
    if (w-divider >= 2*unitSize) {
      cutList.add(1,new cutSegment(x+divider,y,w-divider,h));
    } else {
      cutList.add(new cutSegment(x+divider,y,w-divider,h));
    }
  } else {
    if (divider >= 2*unitSize) {
      cutList.add(1,new cutSegment(x,y,w,divider));
    } else {
      cutList.add(new cutSegment(x,y,w,divider));
    }
    if (h-divider >= 2*unitSize) {
      cutList.add(1,new cutSegment(x,y+divider,w,h-divider));
    } else {
      cutList.add(new cutSegment(x,y+divider,w,h-divider));
    }
  }
}

void keyPressed(){
  if (key == 'x') {
    unitSize = unitSize/2f;
  }
}