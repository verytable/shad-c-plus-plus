#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include <vector>

void PrintContext(const std::vector<std::string> &words, std::vector<int> &positions, int n) {
  for(int i = 0; i < static_cast<int>(positions.size()); ++i) {
    int position = positions[i];
    int left_word_idx = std::max(0, position - n);
    int right_word_idx = std::min(static_cast<int>(words.size()) - 1, position + n);
    for(int word_idx = left_word_idx; word_idx <= right_word_idx; ++word_idx) {
      std::cout << words[word_idx] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::string filename = "";
  std::cin >> filename;
  std::ifstream infile(filename.c_str());
  std::string word = "";
  int n = 0;
  std::cin >> n;
  std::vector<std::string> words;
  std::map<std::string, std::vector<int> > occurrences;
  int position = 0;
  while(infile >> word) {
    words.push_back(word);
    occurrences[word].push_back(position);
    ++position;
  }
  std::string query = "";
  std::cin >> query;
  PrintContext(words, occurrences[query], n);
  return 0;
}
