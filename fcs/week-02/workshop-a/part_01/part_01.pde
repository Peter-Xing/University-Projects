void setup(){
 size(500,500);
 int n = 10;
 int a = width/n;
   for(int i = 0; i < n; i++){
     for(int y = 0; y < n; y++){
       rect(a*i,a*y,width/n,height/n);
   }
 }
}