void setup(){
  size(640, 360);  //coordinate creation
  background(0);   //background color applied
  stroke(153);    //stroke attributes setting
  strokeWeight(4);
  strokeCap(SQUARE);

  int a = 50;      //initialize coordinates parameters
  int b = 120;
  int c = 180;

  line(a, b, a+c, b);       //top left corner picture drawing
  line(a, b+10, a+c, b+10);
  line(a, b+20, a+c, b+20);
  line(a, b+30, a+c, b+30);
  
  line(a+c, b*2, a+2*c, b*2);  //middle bottom picture drawing
  line(a+c, b*2+10, a+2*c, b*2+10);
  line(a+c, b*2+20, a+2*c, b*2+20);
  line(a+c, b*2+30, a+2*c, b*2+30);
  
  line(a+2*c, b, a+3*c, b);    //top right corner picture drawing
  line(a+2*c, b+10, a+3*c, b+10);
  line(a+2*c, b+20, a+3*c, b+20);
  line(a+2*c, b+30, a+3*c, b+30);
}