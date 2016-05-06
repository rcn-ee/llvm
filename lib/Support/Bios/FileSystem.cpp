#include "llvm/Support/Errc.h"
#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Process.h"
#include "llvm/Support/Program.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/Path.h"
#include "llvm/Support/Signals.h"

using namespace llvm;
using namespace sys;
using namespace fs;

std::string llvm::sys::getDefaultTargetTriple()
{
  return ("arm-unknown-linux-gnueabihf");
}

void llvm::sys::RunInterruptHandlers()
{
}

llvm::sys::fs::mapped_file_region::~mapped_file_region()
{
  return;
}

std::error_code llvm::sys::Process::SafelyCloseFileDescriptor(int FD)
{
  return make_error_code(errc::operation_not_permitted);
}

std::error_code llvm::sys::fs::openFileForWrite(const Twine &Name,
                         int &ResultFD, OpenFlags Flags, unsigned Mode)
{
  return make_error_code(errc::operation_not_permitted);
}

std::error_code llvm::sys::ChangeStdoutToBinary()
{
  return make_error_code(errc::operation_not_permitted);
}


#if 0
std::error_code llvm::sys::fs::access(const Twine &Path, AccessMode Mode){

return make_error_code(errc::operation_not_permitted);
}

std::error_code llvm::sys::fs::create_directory(const Twine &path, bool IgnoreExisting = true){
return make_error_code(errc::operation_not_permitted);
}

std::error_code llvm::sys::fs::current_path(SmallVectorImpl<char> &result){
return make_error_code(errc::operation_not_permitted);
}

std::error_code llvm::sys::fs::status(int FD, file_status &Result)
{
return make_error_code(errc::operation_not_permitted);
}

std::error_code llvm::sys::fs::status(const Twine &path, file_status &result)
{
return make_error_code(errc::operation_not_permitted);
}


std::error_code llvm::sys::fs::openFileForRead(const Twine &Name, int &ResultFD)
{
return make_error_code(errc::operation_not_permitted);
}

llvm::sys::fs::mapped_file_region::mapped_file_region(int fd, mapmode mode, uint64_t length, uint64_t offset,
                     std::error_code &ec)
{
  ec = make_error_code(errc::operation_not_permitted);
  return;
}

int llvm::sys::fs::mapped_file_region::alignment()
{
 
  return (0);
}


const char * llvm::sys::fs::mapped_file_region::const_data() const
{

return ("error");
}

UniqueID llvm::sys::fs::file_status::getUniqueID() const
{
 return;
}

Optional<std::string> llvm::sys::Process::GetEnv(StringRef name)
{
llvm::Optional<std::string> FoundPath;
return FoundPath;
}


std::error_code llvm::sys::ChangeStdinToBinary()
{
return make_error_code(errc::operation_not_permitted);
}

 
 void llvm::sys::path::system_temp_directory(bool erasedOnReboot, SmallVectorImpl<char> &result)
 {
 return;
 }
#endif

