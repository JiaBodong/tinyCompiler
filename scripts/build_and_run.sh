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

# run the generated llvm ir code
echo "Running the generated llvm ir code:"
lli build/llvm/jlc_generated_linked.bc