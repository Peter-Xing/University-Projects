// Code to analyse:
// some lines of code do not have semicolon at the end of the line

// we should give answer a default data type of integer
// and have an integer return value
int subtraction(float a, float b){
    int answer = int (a - b);
    return answer;
}

// the println should be inside the void setup() block in order to execute
void setup(){
 size(300,300);
 background(subtraction(-1,55.0));
 println("Your subtraction is <" + subtraction(-1, 55.0) + ">");
}

// the coordinates should be within the setup size of canvas in order to appear
void draw(){
  fill(23);
    text("Subtraction is one of the main arithmetical operations.", 100, 100);
}
