//===-- driver/cl_options.h - LDC command line options ----------*- C++ -*-===//
//
//                         LDC – the LLVM D compiler
//
// This file is distributed under the BSD-style LDC license. See the LICENSE
// file for details.
//
//===----------------------------------------------------------------------===//
//
// Defines the LDC command line options as handled using the LLVM command
// line parsing library.
//
//===----------------------------------------------------------------------===//

#ifndef LDC_DRIVER_CL_OPTIONS_H
#define LDC_DRIVER_CL_OPTIONS_H

#include "driver/targetmachine.h"
#include "gen/cl_helpers.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Support/CodeGen.h"
#include "llvm/Support/CommandLine.h"
#include <deque>
#include <vector>

// FIXME: Just for the BOUDNSCHECK enum; this is not pretty
#include "globals.h"

namespace opts {
namespace cl = llvm::cl;

/// Stores the commandline arguments list, including the ones specified by the
/// config and response files.
extern llvm::SmallVector<const char *, 32> allArguments;

/* Mostly generated with the following command:
   egrep -e '^(cl::|#if|#e)' gen/cl_options.cpp \
    | sed -re 's/^(cl::.*)\(.*$/    extern \1;/'
 */
extern cl::list<std::string> fileList;
extern cl::list<std::string> runargs;
extern cl::opt<bool> compileOnly;
extern cl::opt<bool, true> enforcePropertySyntax;
extern cl::opt<bool> noAsm;
extern cl::opt<bool> dontWriteObj;
extern cl::opt<std::string> objectFile;
extern cl::opt<std::string> objectDir;
extern cl::opt<std::string> soname;
extern cl::opt<bool> output_bc;
extern cl::opt<bool> output_ll;
extern cl::opt<bool> output_s;
extern cl::opt<cl::boolOrDefault> output_o;
extern cl::opt<bool, true> disableRedZone;
extern cl::opt<std::string> ddocDir;
extern cl::opt<std::string> ddocFile;
extern cl::opt<std::string> jsonFile;
extern cl::opt<std::string> hdrDir;
extern cl::opt<std::string> hdrFile;
extern cl::list<std::string> versions;
extern cl::list<std::string> transitions;
extern cl::opt<std::string> moduleDeps;
extern cl::opt<std::string> cacheDir;
extern cl::opt<bool> cacheSourceFiles;

extern cl::opt<std::string> mArch;
extern cl::opt<bool> m32bits;
extern cl::opt<bool> m64bits;
extern cl::opt<std::string> mCPU;
extern cl::list<std::string> mAttrs;
extern cl::opt<std::string> mTargetTriple;
#if LDC_LLVM_VER >= 307
extern cl::opt<std::string> mABI;
#endif
extern cl::opt<llvm::Reloc::Model> mRelocModel;
extern cl::opt<llvm::CodeModel::Model> mCodeModel;
extern cl::opt<bool> disableFpElim;
extern cl::opt<FloatABI::Type> mFloatABI;
extern cl::opt<bool, true> singleObj;
extern cl::opt<bool> linkonceTemplates;
extern cl::opt<bool> disableLinkerStripDead;

extern cl::opt<BOUNDSCHECK> boundsCheck;
extern bool nonSafeBoundsChecks;

extern cl::opt<unsigned, true> nestedTemplateDepth;

#if LDC_WITH_PGO
extern cl::opt<std::string> genfileInstrProf;
extern cl::opt<std::string> usefileInstrProf;
#endif
extern cl::opt<bool> instrumentFunctions;

// Arguments to -d-debug
extern std::vector<std::string> debugArgs;
// Arguments to -run

#if LDC_LLVM_VER >= 307
void CreateColorOption();
#endif
}
#endif
