//==================================
// Foundations of Computer Science
// Student: Luoyang Xing
// id: a1756195
// Semester: 2
// Year: 2018
// Practical Exam Number: 01
//===================================

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