#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

int main() {
  std::string filename = "";
  std::cin >> filename;
  std::ifstream infile(filename.c_str());
  std::string word = "";
  std::map<std::string, int> occurrences;
  int max_word_length = 0;
  while(infile >> word) {
    if(occurrences.find(word) == occurrences.end()) {
      occurrences[word] = 1;
      if(word.length() > max_word_length) {
        max_word_length = static_cast<int>(word.length());
      }
    } else {
      occurrences[word] += 1;
    }
  }
  for(std::map<std::string, int>::iterator i = occurrences.begin(); i != occurrences.end(); ++i) {
    std::cout << std::setw(max_word_length) << (*i).first << ": " << (*i).second << std::endl;
  }
  return 0;
}
