float radius;
float w = 100;
float dif = 5;
void setup() {
  size(300,300);
}

void draw() {
  radius =(.25f*pow(w,2)/dif+dif)/2;
  background(100);
  ellipse(width/2,height/2,1,1);
  line(width/2+w/2,height/2,width/2-w/2,height/2);
  noFill();
  
  float a = sqrt(pow((dif-radius),2)+pow((w/2),2));
  float theta = acos((w*w + -2*a*a)/(-2*a*a));
  print(theta + "\n");
  
  arc(width/2,height/2-(dif-radius),radius*2,radius*2,3*PI/2-theta,3*PI/2+theta);
  arc(width/2,height/2+(dif-radius),radius*2,radius*2,PI/2-theta,PI/2+theta);
}

void keyPressed() {
  if (keyCode == UP) {
    dif+=1f;
  }
  if (keyCode == DOWN) {
    dif-=1;
  }
  if (dif >40) {
    dif = 40;
  }
  if (dif<=0) {
    dif=1;
  }
}