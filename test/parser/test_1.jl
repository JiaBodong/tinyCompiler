# int main () {
#   printInt(fact(7)) ;

#   return 0 ;
# }

# // iterative factorial



# int sump(int a,int b) {
#   b = 1;
#   int x = 3;
#   int y = 6;
#   int o = 7;
#   return y;
# }

# int main() {
#   int a = -3;
#   int b =4;
#   int x,y=7;
#   x = -999;
#   a = b;
#   double c = 3.0;
#   c = 4.0;
#   c = 9.0;
#   printInt(a);
#   printInt(x);
#   printDouble(c);
#   return 1;
# }
#include<stdio.h>




# int subb(int x){
#   x--;
#   return x;
# }

# int main() {
    
#     int y = 101325;
#     int a =11;
    


#     while(y>a){
#         y=subb(subb(y));
#         printInt(y);
#     }
#     return 0;

# }



# int main() {
#     double dA;
#     double dB;
#     dA=0.0014;
#     dB=0.0004;
#     if (dA-dB == 0.001) {
#         printInt(99);
#     }
#     int iA;
#     int iB;
#     iA=342;
#     iB=5120011;
#     printInt(iA-iB);
#     printInt(iA*iB);
#     printInt(iA*2);
#     printInt(3*7);
#     return 0;
# }




# int main() {
#   int a =1;
#   boolean x =a>= 3; 
#   boolean y = a<0||a>1;
#   x = a>0;
#   printBool(test(3) && test(-5));

#   return 0 ;

# }

# void printBool(boolean b) {
#   if (!b) {
#     printString("false");
#   } else {
#     printString("true");
#  }
#  return;
# }

# boolean test(int i) {
#   printInt(i);
#   return i > 0;
# }


# int main() { 
#     boolean b=false;
#     boolean a =true;
#     while(b&&a){}
#     while(false){}
#     return 0; 
# }





# int main(){
#     boolean a = true;
#     boolean b =!a;
#     if(a==b){
#         printInt(1);
#     }
#     else{
#         printInt(0);
#     }
#     return 0;
# }



int main() {
    int x = 56;
    int y = -23;
    printInt(x+y);
    printInt(x-y);
    printInt(x*y);
    printInt(45/2);
    printInt(78%3);
    double z = -9.3;
    double w = 5.1;
    printBool(z+w > z-w);
    printBool(z/w <= z*w);
    return 0 ;
}

void printBool(boolean b) {
  if (b) {
    printString("true");
    return;
  } else {
    printString("false");
    return;
 }
}








    












