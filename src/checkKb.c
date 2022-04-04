// Nathan Johnson
// Tiaron Starrine

//https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

#include "main.h"
#include "dependencies.h"

char checkKb() {
  
  if (GetKeyState(0x57) < 0) return 'w';
  if (GetKeyState(0x41) < 0) return 'a';
  if (GetKeyState(0x53) < 0) return 's';
  if (GetKeyState(0x44) < 0) return 'd';
  
  return '\0';

}