// declaration and initialization in same statement
int f(int x) {
  return x;
}

int main() {
 int x=7, y=f(1), z;
 printInt(x);
 if (x == 7){
    int y = 8;
    printInt(y);
 }
 y = 9;
 return 0 ;
}