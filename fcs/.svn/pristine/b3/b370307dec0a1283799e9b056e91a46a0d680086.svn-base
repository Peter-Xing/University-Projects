//==================================
// Foundations of Computer Science
// Student: Luoyang Xing
// id: a1756195
// Semester: 2
// Year: 2018
// Practical Exam Number: 01
//===================================

size(640, 360);        // set the parameter needed to draw the picture
background(0);
stroke(153);
strokeWeight(4);
strokeCap(SQUARE);

int a = 50;            // set the basic coordinates 
int b = 120;
int c = 180;

line(a, b, a+c, b);    // draw the top left part
line(a, b+10, a+c, b+10);
line(a, b+20, a+c, b+20);
line(a, b+30, a+c, b+30);

for(int i = 0; i < 40; i = i+10){    // draw the part at the bottom
  line(a+c,2*b+i,a+2*c,2*b+i);
}

for(int i = 0; i < 40; i = i+10){    // draw the part at the top right corner
  line(a+2*c,b+i,a+3*c,b+i);
}