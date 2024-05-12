Readme.
X86Backend 1st Version.

Finished:
This is a basic X86-64 compiler. It implements partial functionalities of a subset of the C language, including printing linkage, stack allocation for basic variables, operations on variable immediates, storage of floating-point numbers and string global data, generation of conditional branch and bool labels, function label generation, as well as basic function call and return functionalities.

Problems:
There are currently three remaining issues: 1: Handling FunEapp as a subexpression, and the required peephole optimization. 2: There may be problems with the use of some X64 registers of BOOL. 3: Simple register allocation, used for many parameter transfer, etc.