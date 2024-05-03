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

void many_params(double x1, double x2, double x3, double x4,
                double d1, double d2, double d3, double d4) {
  printDouble(x1);
  printDouble(x2);
  printDouble(x4);
  printDouble(x3);
  printDouble(d1);
}

int main() {
  int a =1;
  int b =a;
  many_params(1.0,2.0,3.0,4.0,
              100.0,100.0,100.0,100.0);
  return 0;
}


