void setup(){
  size(320,320);       //coordinate creation
  background(66);      //background color applied
  int number_a = 150;   //initialize number_a
  int number_b = 26;   //initialize number_b
  float C = 0;           //initialize C
  C = number_a / number_b;  //value of C is division of number_a by number_b
  text("The division of "+number_a+" and "+number_b+" is "+C,160,160);
    /* put the answer at the correct coordinate*/
}