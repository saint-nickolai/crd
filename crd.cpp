/*
  crd.cpp
  C++ Compile, Run, and Delete 
  Nick Howard, Oct 21, 2025
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

int main(int argc, char* argv[]){
  string command = "c++ ";
  string fileArg = argv[1]; 
  string compile = command + fileArg; 

  FILE* pipe = popen(compile.c_str(), "w");

  chrono::milliseconds timespan(1500);
  this_thread::sleep_for(timespan);

  if (argc > 2) {
    string a = "./a.out", b;
    for (int i = 2; i < argc; i++) {
      b = argv[i];
      a = a + " " + b;
    }
    pipe = popen(a.c_str(), "r");
  } else 
    pipe = popen("./a.out", "r");

  char buffer[128];
  while (fgets(buffer, sizeof(buffer), pipe) != NULL)
    printf("%s", buffer);

  pipe = popen("rm a.out", "w");
  pclose(pipe);
  return EXIT_SUCCESS;
}
