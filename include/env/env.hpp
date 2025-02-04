#pragma once

#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <iostream>

inline bool envFileExists (const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

// Return content
std::string envFileContent(const std::string& name) {
    std::ifstream file(name);
    std::string content;

    file >> content;

    file.close();
    return content;
}
