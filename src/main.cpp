// Copyright 2022 NNTU-CS
#include "tree.h"
#include <iostream>
#include <vector>
#include <chrono>

void print_duration(PMTree& tree, size_t length, int num_func, int n=-1) {
  auto start = std::chrono::high_resolution_clock::now();
  if (num_func == 0) {
    getAllPerms(tree);
  } else if (num_func == 1) {
    getPerm1(tree, n);
  } else if (num_func == 2) {
    getPerm2(tree, n);
  }
  auto end = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

  std::cout << "for an alphabet of length " << length << " the running time is : " 
    << duration.count() << " mcs" << std::endl;
}


int main() {
  std::vector<char> test_data_1 = { '1' };
  std::vector<char> test_data_2 = { '1', '2' };
  std::vector<char> test_data_3 = { '1', '2', '3' };
  std::vector<char> test_data_4 = { '1', '2', '3', '4' };
  std::vector<char> test_data_5 = { '1', '2', '3', '4', '5' };
  std::vector<char> test_data_6 = { '1', '2', '3', '4', '5', '6' };
  std::vector<char> test_data_7 = { '1', '2', '3', '4', '5', '6', '7' };
  std::vector<char> test_data_8 = { '1', '2', '3', '4', '5', '6', '7', '8' };
  std::vector<char> test_data_9 = { '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  std::vector<char> test_data_10 = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
  PMTree tree_1(test_data_1);
  PMTree tree_2(test_data_2);
  PMTree tree_3(test_data_3);
  PMTree tree_4(test_data_4);
  PMTree tree_5(test_data_5);
  PMTree tree_6(test_data_6);
  PMTree tree_7(test_data_7);
  PMTree tree_8(test_data_8);
  PMTree tree_9(test_data_9);
  PMTree tree_10(test_data_10);

  std::cout << "Вычисления для getPermAll" << std::endl;
  print_duration(tree_1, 1, 0);
  print_duration(tree_2, 2, 0);
  print_duration(tree_3, 3, 0);
  print_duration(tree_4, 4, 0);
  print_duration(tree_5, 5, 0);
  print_duration(tree_6, 6, 0);
  print_duration(tree_7, 7, 0);
  print_duration(tree_8, 8, 0);
  print_duration(tree_9, 9, 0);
  print_duration(tree_10, 10, 0);
  std::cout << std::endl;

  std::cout << "Вычисления для getPerm1" << std::endl;
  print_duration(tree_1, 1, 1, 1);
  print_duration(tree_2, 2, 1, 1);
  print_duration(tree_3, 3, 1, 2);
  print_duration(tree_4, 4, 1, 3);
  print_duration(tree_5, 5, 1, 12);
  print_duration(tree_6, 6, 1, 6);
  print_duration(tree_7, 7, 1, 45);
  print_duration(tree_8, 8, 1, 62);
  print_duration(tree_9, 9, 1, 13);
  print_duration(tree_10, 10, 1, 101);
  std::cout << std::endl;

  std::cout << "Вычисления для getPerm2" << std::endl;
  print_duration(tree_1, 1, 2, 1);
  print_duration(tree_2, 2, 2, 1);
  print_duration(tree_3, 3, 2, 2);
  print_duration(tree_4, 4, 2, 3);
  print_duration(tree_5, 5, 2, 12);
  print_duration(tree_6, 6, 2, 6);
  print_duration(tree_7, 7, 2, 45);
  print_duration(tree_8, 8, 2, 62);
  print_duration(tree_9, 9, 2, 13);
  print_duration(tree_10, 10, 2, 101);
  std::cout << std::endl;
  return 0;
}
