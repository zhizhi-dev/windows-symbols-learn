#ifndef HELLO_H_
#define HELLO_H_

#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

// define at dl.lib by dl.def
_declspec(dllimport) int __stdcall Hello(
    const char* message);  

  // define at d2.lib by d2.def
_declspec(dllimport) int __stdcall Hello2(
    const char* message);

  // define at symbols.asm
int __stdcall Hello3(const char* message);

// defint by __identifer("_impl__Hello4@4")
_declspec(dllimport) int __stdcall Hello4(
    const char* message);  


int __stdcall Hello5(const char* message);

 // defint by #pragma comment(linker, "/ALTERNATENAME:__imp__Hello6@4=__impl__Hello@4")
_declspec(dllimport) int __stdcall Hello6(
    const char* message); 

#ifdef __cplusplus
}
#endif

#endif //  HELLO_H_
