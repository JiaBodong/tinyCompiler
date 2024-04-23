# set -x
mkdir -p build/llvm
rm -rf build/llvm/*
# generate the llvm ir code
./jlc -s test/parser/test_1.jl > build/llvm/jlc_generated.ll
# compile the generated llvm ir code
llvm-as build/llvm/jlc_generated.ll -o build/llvm/jlc_generated.bc
llvm-as lib/runtime.ll  -o build/llvm/runtime.bc

# link the generated llvm ir code to bc file
llvm-link build/llvm/jlc_generated.bc build/llvm/runtime.bc -o build/llvm/jlc_generated_linked.bc
# opt -load src/llvm-pass/BaseRegAlloc.so -mypass < build/llvm/jlc_generated_linked.bc > build/llvm/jlc_generated_linked.bc


# run the generated llvm ir code
echo "Running the generated llvm ir code:"
echo "-----------------------------------"
lli build/llvm/jlc_generated_linked.bc
echo "-----------------------------------"

# assembly code generation
llc -filetype=asm build/llvm/jlc_generated_linked.bc -o build/llvm/jlc_generated_linked.s

echo "-----------------------------------"
echo "X86 Assembly code generated successfully."
echo "You can find the output file at: build/llvm/jlc_generated_linked.s"
echo "-----------------------------------"
