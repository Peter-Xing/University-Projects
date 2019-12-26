// Question 2
int[] swapArray(int[] array){
  int a = 0;
  a = array[0];                  // swap the numbers
  array[0] = array[1];
  array[1] = a;
  return array;
}


// Question 3                  
int sumArray(int[] array){
  int sum = 0;
  for (int i = 0 ; i<array.length; i++){
    sum = sum + array[i];
  }
  return sum;
}


// Question 4
int sum2DArray(int array[][]){
  int sum = 0;
  for (int i = 0; i< array.length; i++){
    for (int j = 0; j < array[i].length; j++){
      sum += array[i][j];
    } 
  }
  return sum;
}

// Question 5
int[] sumRows(int array[][]){
  int result []  = new int[array.length];
  for (int i = 0; i< array.length; i++){
    int sum = 0;
    for (int j = 0; j < array[i].length; j++){
      sum += array[i][j];
    }
    result[i]=sum;
  }
  return result;
}

// Question 6
int [] sumCols(int array[][]){
  int result []  = new int[array.length];
  for (int j = 0; j< array[0].length; j++){
    int sum = 0;
    for (int i = 0; i< array.length; i++){
      sum += array[i][j];
      }
      result[j]=sum;
    }
  return result;
}

//Question 7
float avgOfArray(int array[][]){
  int u = 0;
  for (int i = 0; i< array.length; i++){        // get the number of elements in array
    for (int j = 0; j < array[i].length; j++){
      u++;
    } 
  }
  int [] x = sumRows(array);                  // sum the rows
  int o = sumArray(x);                        // sum of all elements
  float avg = o/u;
  return avg;
}

// function call
void setup(){
  size (300,300);
  int [] x = {1,3}; //Q 2
  swapArray(x);
  println(x);
  int [] y = {1,2,3,4,5,6}; //Q 3 
  text("result = "+sumArray(y),20,20);
  int [][] z = {{1,2,3},{1,2,3},{1,2,3}}; //Q4
  text("result = "+sum2DArray(z),20,40);
  int [][] p = {{1,2,3},{2,3,4},{3,5,4}};  //Q5
  println(sumRows(p));
  println(sumCols(p));                     // Q6
  int [][] h = {{1,2,3},{1,2,3},{1,2,3}}; //Q7
  text(int(avgOfArray(h)),20,80);
}