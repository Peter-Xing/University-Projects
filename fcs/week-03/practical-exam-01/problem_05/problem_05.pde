int cumulative_sum (int [] array){
  int sum = 0;                      
  for(int i=0; i<array.length; i++){ // get the sum of array by for loop
    sum = sum +array[i];
  }
  return sum;
}

// using unit tests to check the function
void setup(){
  int [] a = {1,2,3};
  int [] b = {1,1};
  int [] c = {1,1,1};
  int [] d = {4,4,4};
  println(cumulative_sum(a));
  println(cumulative_sum(b));
  println(cumulative_sum(c));
  println(cumulative_sum(d));
}
