// Test that maximum function counts are set correctly (LLVM >= 3.8)
// REQUIRES: atleast_llvm308

// RUN: %ldc -fprofile-instr-generate=%t.profraw -run %s  \
// RUN:   &&  %profdata merge %t.profraw -o %t.profdata \
// RUN:   &&  %ldc -c -output-ll -of=%t2.ll -fprofile-instr-use=%t.profdata %s \
// RUN:   &&  FileCheck %s < %t2.ll

// CHECK: !{{[0-9]+}} = !{i32 1, !"MaxFunctionCount", i32 2}

void foo() {}
void bar() {}

void main() {
  foo();
  bar();
  bar();
}
