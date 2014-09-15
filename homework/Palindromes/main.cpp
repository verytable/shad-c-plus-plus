#include <iostream>
#include <fstream>

bool IsPalindrome(const std::string &str) {
  bool is_palindrome = true;
  for (int position = 0; position < str.length() && is_palindrome; ++position) {
    if (str[position] != str[str.length() - 1 - position]) {
      is_palindrome = false;
    }
  }
  return is_palindrome;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::string line = "";
  while (std::getline(std::cin, line)) {
    if (IsPalindrome(line)) {
      std::cout << line << std::endl;
    }
  }
  return 0;
}
