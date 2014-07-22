//==-- C6000.h - Top-level interface for MSP430 representation ---*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM C6000 backend.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_TARGET_C6000_H
#define LLVM_TARGET_C6000_H

#include "MCTargetDesc/C6000MCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class C6000TargetMachine;

/// \brief Creates an C6000-specific Target Transformation Info pass.
ImmutablePass *createC6000TargetTransformInfoPass(const C6000TargetMachine *TM);
} // end namespace llvm;

#endif
