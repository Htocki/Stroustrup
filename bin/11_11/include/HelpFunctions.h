#pragma once

#include <string>
#include <vector>

std::vector<std::string> Split(
  const std::string& string,
  const std::string& whitespaces
);

void Print(const std::vector<std::string> vector);
