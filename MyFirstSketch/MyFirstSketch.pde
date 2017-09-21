int[] rgb = new int[] {0,0,0};
float camX, camY = 0;
boolean[] dir = new boolean[] {true,true,true};
int active = (int)random(3);
color c = color(0,0,0);
float bigCircle;
float littleCircle;
float otherLittleCircle;

void setup() {
  bigCircle = random(360);
  randomSeed((int)random(1000));
  littleCircle = random(360);
  otherLittleCircle = random(360);
  size(460,360);
  strokeWeight(1);
  background(0);
}
void draw() {
  camX+=0.1f;
  camY+=0.1f;
  //camera(width/2, height/2.0, (height/2.0) / tan(PI*30.0 / 180.0), width/2.0, height/2.0, 0, 0, 1, 0);  
  bigCircle+=1.034f;
  translate(camX,camY);
  littleCircle+=8.487f;
  otherLittleCircle+=4.983f;
  bigCircle %= 360;
  littleCircle %= 360;
  otherLittleCircle %= 360;
  rgb[active] += (dir[active]) ?1:-1;
  c = color(rgb[0],rgb[1],rgb[2]);
  stroke(c);
  line(width/2+cos(bigCircle*(PI/180f))*100+cos(littleCircle*(PI/180f))*100,height/2+sin(bigCircle*(PI/180f))*50+sin(littleCircle*(PI/180f))*100,width/2+cos(otherLittleCircle*(PI/180f))*50,height/2+sin(otherLittleCircle*(PI/180f))*50);
  
  if ((rgb[active] == 255 && dir[active]==true) || (rgb[active] == 0 && dir[active]==false)) {
    dir[active] = !dir[active];
    changeActive();
  } else if (random(0,100) == 0) {
      changeActive();  }
}
void changeActive() {
  int oldActive = active;
      while (active == oldActive) {
        active = (int)random(3);
      }
}