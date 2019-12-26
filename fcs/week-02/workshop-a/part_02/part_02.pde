void setup(){
 size(500,500);
 int n = 50;
 int a = width/n;
   for(int i = 0; i < n; i++){
     for(int y = 0; y < n; y++){
       fill(10+5*i,255-5*y,100+5*i);
       rect(a*i,a*y,width/n,height/n);
   }
 }
}