Instruction for source code install of nasm asm

1. go to web address , download tar file

2. tar -zxvf nasm-x.x.tar.gz

3. cd nasm-x.x

4. ./configure --prefix=/your-path/nasm

5. make

6. sudo make install

7. nasm -v 

<!-- using for asm -->
8. /you=path/nasm/bin/nasm -f elf64 ....  
    example: 
        /chalmers/users/bodong/nasm/bin/nasm -f elf64 test.asm -o test.o
        ld test.o -o example
        ./example



