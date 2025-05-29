#pragma once
// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>

class PMTree {
  struct Node {
    char data;
    std::vector<Node*> nodes;
    Node(char d, std::vector<Node*>& n) : data(d), nodes(n) {}
  };

  Node* root;

  void create_tree(Node*, const std::vector<char>&);
  void perms(Node*, std::vector<std::vector<char>>&, std::vector<char>&);
  void permNumber(Node*, std::vector<char>&, int);
public:
  PMTree(const std::vector<char>& data) {
    create_tree(root, data);
  }

  void create(std::vector<char>&);

  void getPerms(std::vector<std::vector<char>>&);

  void getPermNumber(std::vector<char>&, int);
};

std::vector<std::vector<char>> getAllPerms(PMTree&);

std::vector<char> getPerm1(PMTree&, int);

std::vector<char> getPerm2(PMTree&, int);

#endif  // INCLUDE_TREE_H_
