#include "timecard.h"

static int N;

void init(int n) {
  N = n;
}

std::string convert(std::string s) {
  if (s[0] == 'A') s[0] = 'a';
  return s;
}
