float unitSize;
float zoom = 1;
PImage screen;
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
  size(512,512);
  xo = width/2;
  yo = height/2;
  unitSize = width/16f;
  cutList.add(new cutSegment(0-width/2,0-width/2,width,height));
  xo = width/2;
  yo = height/2;
}
void draw() {
  //delay(500);
  translate (xo, yo);
  scale(zoom);
  fill(120);
  ellipse(0, 0, 40, 40);
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
    Zoom(1.01f);
  }
  if (key == 'z') {
    Zoom(.99f);
  }
  if (key == 'a') {
    zoom+=0.01f;
    print(zoom+"\n");
  }
}

void Zoom(float factor) {
  screen = createImage(width,height,RGB);
  for (int i = 0; i < width*height; i++) {
    screen.pixels[i] = get(i%width,i/width);
  }
  screen.resize(floor(width*factor),floor(height*factor));
  image(screen,floor(-width*(factor-1)/2-width/2),floor(-height*(factor-1)/2-height/2));
  zoom*=factor;
}