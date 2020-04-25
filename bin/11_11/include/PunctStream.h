#pragma once

#include <ios>
#include <iterator>
#include <sstream>
#include <string>

class PunctStream {
 public:
  explicit PunctStream(std::istream& istream);
  void SetWhitespaces(const std::string& whitespaces);
  void AddWhitespace(char character);
  bool IsWhitespace(char character);
  PunctStream& operator>> (std::string& string);
  operator bool();

 private:
  std::istream& m_istream;
  std::istringstream m_buffer;
  std::string m_whitespaces;
};
