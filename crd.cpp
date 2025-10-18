/*
  cnr.cpp
  C++ compile and run
  Nick Howard, Oct 17, 2025
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

  chrono::milliseconds timespan(1000);
  this_thread::sleep_for(timespan);

  pipe = popen("./a.out", "r");
  
  char buffer[128];
  while (fgets(buffer, sizeof(buffer), pipe) != NULL)
    printf("%s", buffer);

  pipe = popen("rm a.out", "w");
  pclose(pipe);
  return EXIT_SUCCESS;
}
