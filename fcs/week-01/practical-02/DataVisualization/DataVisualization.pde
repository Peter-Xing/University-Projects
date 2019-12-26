void setup() {
  size(600, 600);
  
  line(width*0.05,height*0.05,width*0.05,height-height*0.05);      // start drawing the grid
  line(width*0.05,height-height*0.05,width-width*0.05,height-height*0.05);
  for (int i=0; i<20; i++){
    stroke(166);
    line(width*0.095+i*width*0.045,height*0.05,
         width*0.095+i*width*0.045,height-height*0.05);
    line(width*0.05,height*0.05+i*height*0.045,
         width - width*0.05, height*0.05+i*height*0.045);     // done drawing the grid
       }
  
  
  float avg = 0;              // initialize the parameters
  float sum = 0;
  
  
  float h = (height*0.9)/10;   // set the height of the bars
  for (int i=0; i<10; i++) {
    float r = random(0, 20);  // in the loop, get 10 random positive integers
    r = round(r);             // round the float into integer
    rectMode(CORNER);
    if(r%2==0){               // change color by the number
      fill(0,300-28*(r/2),0);  // add color for even numbers
      rect(width*0.05,height*0.05+i*h,width*0.045*r,h);   // draw bars of each random number
    }
    else {
      fill(300-28*((r-1)/2),0,0);  // add color for odd numbers
      rect(width*0.05,height*0.05+i*h,width*0.045*r,h);  
  }
    fill(20,20,20);
    textSize(height/30);
    text(int(r),width*0.06+width*0.045*r,height*0.05+i*h+h/2);// place the number beside the bar
    sum = sum + r;            // sum up the integers
  }
 
 
  avg = sum/10;               // get the average of the integers
  fill(1000,0,0);
  text("avg: "+avg, width*0.015+width*0.045*avg,height*0.025);
  stroke(2000,0,0);
  strokeWeight(2);            // make the average line more obvious
  line(width*0.05+width*0.045*avg,height*0.05,
       width*0.05+width*0.045*avg,height-height*0.05); //draw the avg line

  



}