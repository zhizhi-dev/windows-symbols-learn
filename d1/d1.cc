#include <stdio.h>

extern "C" _declspec(dllexport) int __stdcall Hello(const char* message) {
  printf("dl.Hello: %s\n", message);
  return 0;
}