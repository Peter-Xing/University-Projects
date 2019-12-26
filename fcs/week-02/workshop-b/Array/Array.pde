void setup(){
  size(330,330);
  
  float [] tem = {38.6,36.2,34,32.5,26.9,28.8,32.2,33,32.9,31.5,
                30.7,21.7,23.4,30.2,35.4,23.3,27.3,33.5,34.6,34.4,
                29.9,22.6,29,32.5,27.7,33.3,23.9,24.6,22.7,19.7,20.1};
                
  int n = 31;
  int a = 0;
  int b = 0;
  int c = 0;
  int d = 0;
  int e = 0;
  for(int i = 0; i < n; i++){
    if(tem[i]<=10){a++;}
    else if(tem[i]<=20) {b++;}
    else if(tem[i]<=30) {c++;}
    else if(tem[i]<=40) {d++;}
    else if(tem[i]<=50) {e++;}
  }
  textSize(26);
  fill(0,102,153);
  text("0-10 degrees: "+a, 20,20);
  text("11-20 degrees: "+b, 20,50);
  text("21-30 degrees: "+c, 20,80);
  text("31-40 degrees: "+d, 20,110);
  text("41-50 degrees: "+e, 20,140);
}