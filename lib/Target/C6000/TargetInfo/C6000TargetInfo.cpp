//===-- C6000TargetInfo.cpp - C6000 Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "C6000.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target llvm::TheC6000Target;

extern "C" void LLVMInitializeC6000TargetInfo() {
  RegisterTarget<Triple::c6000, /*HasJIT=*/ false>
    X(TheC6000Target, "c6000", "C6000");
}
