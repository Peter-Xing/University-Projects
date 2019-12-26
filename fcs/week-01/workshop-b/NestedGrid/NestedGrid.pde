void setup(){
 size(600,600);
 int a = 50;
 for(int i = 1; i < 11; i++){
   for(int y = 1; y < 11; y++){
     rect(a*i,a*y,50,50);
   }
 }
}