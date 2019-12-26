void setup() {
  size(200, 200);               //setup canvas
  text(factorial(0), 60, 100);  //teting cases
  text(factorial(1), 60, 120);
  text(factorial(3), 60, 140);
  text(factorial(7), 60, 160);
}

int factorial(int n) {            //design the function factorial
  int factorial = 1;       
  for (int i = 1; i < n+1; i++) {  //construct the function
    factorial = factorial * i;
  }
  return factorial;              //return the factorial value
}
// the original bug was starting the multiplication from 0, which should be 1 instead