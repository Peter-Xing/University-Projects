void drawFourLines(int [] array){
  int a = array[0];             //get the coordinates out of the array
  int b = array[1];
  int c = 180;
  
  line(a-c, b, a, b);           //picture drawing
  line(a-c, b+10, a, b+10);
  line(a-c, b+20, a, b+20);
  line(a-c, b+30, a, b+30);}
  
// function call
void setup() {  
  size(640, 360);  //coordinate creation
  background(0);   //background color applied
  stroke(153);    //stroke attributes setting
  strokeWeight(4);
  strokeCap(SQUARE);
  
  int [] h = {200,100}; // input the coordinates three times
  int [] k = {400,260};
  int [] l = {600,100};
  drawFourLines(h);
  drawFourLines(k);
  drawFourLines(l);
}