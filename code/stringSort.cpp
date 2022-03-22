/*
  This code contains a function that takes a string vector and returns
  the same vector with the contents sorted by the length of each element.
*/

#include <iostream>
#include <vector>

std::vector<std::string> sort(std::vector<std::string> s, int n) {
  for (int i = 1; i < n; i++) {
    std::string temp = s[i];

    // Insert s[j] at correct position
    int j = i - 1;
    while (j >= 0 && temp.length() < s[j].length()) {
      s[j + 1] = s[j];
      j--;
    }
    s[j + 1] = temp;
  }
  return s;
}

void print_myvec(std::vector<std::string> my_vec) {
  for (int i = 0; i < my_vec.size(); i++) {
    std::cout << my_vec[i] << " ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<std::string> my_vec = {"a", "ccc", "dddd", "bb"};
  std::vector<std::string> my_vec1 = {"apple", "pie", "shortcake"};
  std::vector<std::string> my_vec2 = {"may", "april", "september", "august"};

  std::cout << "Strings before the sort:" << std::endl;
  print_myvec(my_vec);
  print_myvec(my_vec1);
  print_myvec(my_vec2);

  std::cout << "\n";
  std::cout << "Strings after the sort:" << std::endl;

  my_vec = sort(my_vec, my_vec.size());
  my_vec1 = sort(my_vec1, my_vec1.size());
  my_vec2 = sort(my_vec2, my_vec2.size());

  print_myvec(my_vec);
  print_myvec(my_vec1);
  print_myvec(my_vec2);

  return 0;
}