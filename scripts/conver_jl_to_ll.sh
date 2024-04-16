# this script is used to convert a julia file to llvm file 
# for debug and comparison

echo "" > /tmp/temp.c
echo "extern void printInt(int);" >> /tmp/temp.c
echo "extern void printString(char*);" >> /tmp/temp.c
echo "extern void printDouble(double);" >> /tmp/temp.c
echo "extern int readInt();" >> /tmp/temp.c
echo "extern double readDouble();" >> /tmp/temp.c

cat test/parser/test_1.jl >> /tmp/temp.c

clang -S -O0 -emit-llvm /tmp/temp.c -o test/parser/test.ll