void setup(){
  size(300,300);
  background(0,200,200);
  int sum = 0;
  int a = 10;
  for(int i=0; i<=a; i++){
    if(i%2==0){text(i,20, 20+20*i);
    }
    else{sum = sum + i;}
  }
  text(sum, 40, 20);

}