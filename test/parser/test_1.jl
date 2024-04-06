/* void expression as statement */
void foo() {
  #  printString("foo");
   printInt(1);
   printDouble(1.0);
   printString("foo");
   printString("foo");
   printString("a very long string that should be printed on multiple lines to test the printString function");
   return;
}

int main() {
  foo();
  return 0 ;

}


