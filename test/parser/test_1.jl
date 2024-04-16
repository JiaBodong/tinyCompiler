# int main () {
#   printInt(fact(7)) ;

#   return 0 ;
# }

# // iterative factorial

# int fact (int n) {
#   int i,r ;
#   i = 1 ;
#   r = 1 ;
#   while (i <= n) {
#     r = r * i ;
#     i++ ;
#   }
#   return r ;
# }

int main() {
  int a = 1 ;
  
  while(a < 10) {
    if(a>2){
      int i = 2;
      a =a - i;
    }
    else{
      int i =3;
      a = a +i;
      int a = 3 * a;
      a = a;
    }

  }
  int res =a;
  return 0;
}