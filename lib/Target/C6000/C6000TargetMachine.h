//===-- C6000TargetMachine.h - Define TargetMachine for C6000 ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the C6000 specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//

#ifndef C6000TARGETMACHINE_H
#define C6000TARGETMACHINE_H

#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

class C6000TargetMachine : public LLVMTargetMachine {
  const DataLayout DL;       // Calculates type size & alignment
public:
  C6000TargetMachine(const Target &T, StringRef TT,
                     StringRef CPU, StringRef FS, const TargetOptions &Options,
                     Reloc::Model RM, CodeModel::Model CM,
                     CodeGenOpt::Level OL);

  const DataLayout       *getDataLayout() const override { return &DL; }

  /// \brief Register C6000 analysis passes with a pass manager.
  void addAnalysisPasses(PassManagerBase &PM) override;

  // Pass Pipeline Configuration
  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;
};

} // end namespace llvm

#endif
