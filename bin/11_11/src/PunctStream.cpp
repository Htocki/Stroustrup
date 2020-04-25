#include "PunctStream.h"

PunctStream::PunctStream(std::istream& istream)
  : m_istream { istream }
{}

inline void PunctStream::SetWhitespaces(const std::string& whitespaces) {
  m_whitespaces = whitespaces;
}

inline void PunctStream::AddWhitespace(char character) {
  m_whitespaces += character;
}

bool PunctStream::IsWhitespace(char character) {
  if (m_whitespaces.find(character) == std::string::npos) {
    return false;
  }
  return true;
}

PunctStream& PunctStream::operator>>(std::string& string) {
  while (!(m_buffer >> string)) {
    if (m_buffer.bad() || !m_istream.good()) { return *this; }

    m_buffer.clear();
    std::string line;
    std::getline(m_istream, line);

    for (char& character : line) {
      if (IsWhitespace(character)) { character = ' '; }
    }

    m_buffer.str(line);
  }
  return *this;
}

PunctStream::operator bool() {
  return !(m_istream.fail() || m_istream.bad())
    && m_istream.good();
}
