
String name = "Peter Xing"; // name is a string variable

String family_name ="Xing";    // family name is also a string variable

int age = 22; //age is an integer number

float salary = 4000.5; // salary represents money, which is a float type variable

String gender = "Male"; //gender is one of several choices, which is a string type variable

boolean is_member = false; //is_member is a yes or no choice, so it is  a boolean variable

void setup(){
  size(300,300);
  text("name: "+name, 100,20);   //display the variables on the canvas
  text("family name: "+family_name, 100,40);
  text("age: "+age, 100,60);
  text("salary: "+salary, 100,80);
  text("gender: "+name, 100,100);
  text("is member: "+is_member, 100,120);
}
