// declaration and initialization in same statement
int f(int x, int y) {
  return x+y;
}

void b(int x) {
  return;
}

int main() {
 int a = 2;

 f(f(a,1),a);
 b(a);
 printInt(a);
 return 0 ;
}