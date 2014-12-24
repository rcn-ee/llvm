add_llvm_target(C6000CodeGen
  C6000TargetMachine.cpp
  C6000TargetTransformInfo.cpp
  )

add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
