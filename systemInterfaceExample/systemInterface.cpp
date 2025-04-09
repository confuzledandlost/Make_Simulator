#include <sys/types.h>
#include <sys/stat.h>
#include<cerrno>
#include<cstdlib>
#include<iostream>


bool fileExists(std::string nameOfFile) {
  // Given the name of a file, this function returns
  // true, if the file exists. Otherwise, it returns false.

  struct stat finfo;

  return stat( nameOfFile.c_str(), &finfo ) == 0;
}

unsigned long timestampForFile(std::string nameOfFile) {
  // This function returns the timestamp of the files whose name
  // is in arguments "nameOfFile".

  // Pre-condition: fileExists(nameOfFile) is true!

  assert(fileExists(nameOfFile));

  struct stat finfo;
  stat( nameOfFile.c_str(), &finfo );
  return finfo.st_mtime;
}

bool executeCommand( std::string cmnd ) {
  //  Passed the the commond in 'cmnd' to the underlying shell and returns its status.
  //  A return value of zero means that the command terminated 
  //  successfully. A non-zero value means that the shell rejected the command.

  // The function return true if the command ran successfully. Otherwise,
  // it returns false.

    std::cout << cmnd << std::endl;
    return  system( cmnd.c_str() ) == 0;
}
