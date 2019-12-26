
void printArray( int [] array){
  for(int i = 0; i<array.length; i++){
    array[i] = " "+array[i];
  }
 
}

void setup(){
  size(500,500);
  fill(33);
  int [] a = {1,1,1};
  printArray(a);
}
