//===-- C6000TargetTransformInfo.cpp - C6000 specific TTI pass ------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
/// \file
/// This file implements a TargetTransformInfo analysis pass specific to the
/// C6000 target machine. It uses the target's detailed information to provide
/// more precise answers to certain TTI queries, while letting the target
/// independent and default TTI implementations handle the rest.
///
//===----------------------------------------------------------------------===//

#include "C6000.h"
#include "llvm/Analysis/TargetTransformInfo.h"
#include "llvm/Support/Debug.h"
#include "llvm/Target/CostTable.h"
#include "llvm/Target/TargetLowering.h"
using namespace llvm;

#define DEBUG_TYPE "c6000tti"

// Declare the pass initialization routine locally as target-specific passes
// don't have a target-wide initialization entry point, and so we rely on the
// pass constructor initialization.
namespace llvm {
void initializeC6000TTIPass(PassRegistry &);
}

namespace {
class C6000TTI final : public ImmutablePass, public TargetTransformInfo {
  public:
   C6000TTI() : ImmutablePass(ID) {
      llvm_unreachable("This pass cannot be directly constructed");
   }
      
   C6000TTI(const C6000TargetMachine *TM)
      : ImmutablePass(ID) {
    initializeC6000TTIPass(*PassRegistry::getPassRegistry());
  }

  void initializePass() override {
    pushTTIStack(this);
  }

  void getAnalysisUsage(AnalysisUsage &AU) const override {
    TargetTransformInfo::getAnalysisUsage(AU);
  }

  /// Pass identification.
  static char ID;

  /// Provide necessary pointer adjustments for the two base classes.
  void *getAdjustedAnalysisPointer(const void *ID) override {
    if (ID == &TargetTransformInfo::ID)
      return (TargetTransformInfo*)this;
    return this;
  }

  /// \name Vector TTI Implementations
  /// @{

  unsigned getNumberOfRegisters(bool Vector) const override {
    if (Vector)
       return 16;

    return 64;
  }

  unsigned getRegisterBitWidth(bool Vector) const override {
    return 32;
  }

  unsigned getMaximumUnrollFactor() const override {
      return 4;
  }
};

} // end anonymous namespace

INITIALIZE_AG_PASS(C6000TTI, TargetTransformInfo, "c6000tti",
                   "C6000 Target Transform Info", true, true, false)
char C6000TTI::ID = 0;

ImmutablePass *
llvm::createC6000TargetTransformInfoPass(const C6000TargetMachine *TM) {
  return new C6000TTI(TM);
}
