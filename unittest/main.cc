#include <stdio.h>

#include <windows.h>

#include "hello.h"


#pragma comment(lib, "d1.lib")
#pragma comment(lib, "d2.lib")

static int __stdcall HelloImpl(const char* message) {
  printf("Hello: %s\n", message);
  return 0;
}

__declspec(naked) int __stdcall Hello5(const char* message) {
  __asm {
      jmp dword ptr [HelloImpl]
  }
}

__pragma(warning(suppress : 4483)) extern "C" void const* const
    __identifier("_imp__Hello4@4") =
    &HelloImpl;

#pragma comment(linker, "/ALTERNATENAME:__imp__Hello6@4=__imp__Hello@4")

int main(int argc, char** argv) {
  /**
   * dl.def
   * 
   * EXPORTS
   *   Hello
   */
  Hello("Hello");  // call _Hello@0 -- > jmp dword ptr [_imp__Hello@0]


  /**
   * d2.def
   * 
   * EXPORTS
   *   _Hello2@0=d1._Hello@0
   */
  Hello2("Hello2");

  /*
   * .model FLAT
   *
   * extern  __imp__Hello@4:near
   *
   * public  _Hello3@4
   *
   * .code
   *
   * _Hello3@4   proc
   *  jmp   dword ptr [__imp__Hello@4]
   * _Hello3@4 endp
   *
   * end
   *
   */
  Hello3("Hello3");

  /**
   * __pragma(warning(disable : 4483)) extern "C" void const* const
   *   __identifier("_imp__Hello4@4") = &HelloImpl;
   */
  Hello4("Hello4");

  /**
   * __declspec(naked) int __stdcall Hello5() {
   *   __asm {
   *    jmp dword ptr [HelloImpl]
   *  }
   * }
   */
  Hello5("Hello5");


  /**
   * #pragma comment(linker, "/ALTERNATENAME:__imp__Hello6@4=__impl__Hello@4")
   */
  Hello6("Hello6");

  return 0;
}