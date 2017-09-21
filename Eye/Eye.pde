float radius;
float w = 200;
float dif = 5;
float targetDif = 5;
void setup() {
  size(600,600);
}

void draw() {
  
  dif = lerp(dif,targetDif,0.05f);
  if (abs(dif-targetDif) < 1) {
    targetDif = dif;
  }
  
  strokeWeight(5);
  radius =(.25f*pow(w,2)/dif+dif)/2;
  background(100);
  noFill();
  
  float a = sqrt(pow((dif-radius),2)+pow((w/2),2));
  float theta = acos((w*w + -2*a*a)/(-2*a*a));
  
  arc(width/2,height/2-(dif-radius),radius*2,radius*2,3*PI/2-theta/2,3*PI/2+theta/2);
  arc(width/2,height/2+(dif-radius),radius*2,radius*2,PI/2-theta/2,PI/2+theta/2);
  //strokeWeight(1);
  /*beginShape();
  vertex(width/2-w/2,height/2);
  curveVertex(width/2,height/2+dif);
  vertex(width/2+w/2,height/2);
  vertex(width/2,height/2-dif);
  endShape();*/
}

void keyPressed() {
  if (keyCode == UP) {
    //targetDif+=2f;
    targetDif=w*.3f;
  }
  if (keyCode == DOWN) {
    targetDif-=2;
    targetDif=w*0.005f;
  }
  if (targetDif >w*.37f) {
    targetDif = 40;
  }
  if (targetDif<=0) {
    targetDif=1;
  }
}