#include <bits/stdc++.h>

std::string decompress() {
  std::string answer;
  while (true) {
    char read_cache;
    std::cin >> read_cache;
    if (isdigit(read_cache)) {
      int reps = 0;
      do {
        reps = reps * 10 + (read_cache - '0');
        std::cin >> read_cache;
      } while (isdigit(read_cache));
      std::string ins = decompress();
      for (int i = 1; i <= reps; ++i)
        answer += ins;
    }
    else
    if (isalpha(read_cache)) {
      answer += read_cache;
    }
    else
    if (read_cache == ']') {
      break;
    }
    else
      break;
  }
  return answer;
}

int main() {
    std::cout << decompress() << std::endl;
}
