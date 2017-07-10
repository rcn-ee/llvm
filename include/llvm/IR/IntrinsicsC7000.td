//===- IntrinsicsC7000.td - Defines TI C7000 intrinsic   ---*- tablegen -*-===//
// 
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
// 
//===----------------------------------------------------------------------===//
//
// This file defines all of the TI C7000-specific intrinsics.
//
//===----------------------------------------------------------------------===//

let TargetPrefix = "c7x" in {  // All intrinsics start with "llvm.c7x.".

//===-------------------------- C7x Intrinsics --------------------------===//
//
    def int_c7x_recip      : Intrinsic<[llvm_anyfloat_ty], [LLVMMatchType<0>], [IntrNoMem]>;
    def int_c7x_recip_sqrt : Intrinsic<[llvm_anyfloat_ty], [LLVMMatchType<0>], [IntrNoMem]>;
    def int_c7x_abs        : Intrinsic<[llvm_anyfloat_ty], [LLVMMatchType<0>], [IntrNoMem]>;
}
