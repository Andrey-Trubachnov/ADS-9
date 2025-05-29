// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"


void PMTree::create_tree(Node* node, const std::vector<char>& data) {
  if (data.empty()) {
    return;
  }

  if (root == nullptr) {
    std::vector<Node*> nodes; // Создаем связи от корня
    for (int i = 0; i < data.size(); ++i) {
      std::vector<Node*> leaf_nodes(data.size() - 1); // Создаем связи от листа
      Node* n = new Node(data[i], leaf_nodes); // Создаем лист
      nodes.push_back(n);
    }

    Node* obj = new Node('\0', nodes); // Создаем корень

    root = obj;
    
    for (int i = 0; i < data.size(); ++i) {
      std::vector<char> t = data;
      t.erase(t.begin() + i);
      create_tree(root->nodes[i], t);
    }

    return;
  }

  for (int i = 0; i < data.size(); ++i) {
    std::vector<Node*> leaf_nodes(data.size() - 1); // Создаем связи от листа
    Node* n = new Node(data[i], leaf_nodes); // Создаем лист
    node->nodes[i] = n;

    std::vector<char> t = data;
    t.erase(t.begin() + i);
    create_tree(n, t);
  }
}

void PMTree::perms(Node* node, std::vector<std::vector<char>>& res, std::vector<char>& perm) {
  if (node->data != '\0') {
    perm.push_back(node->data);
  }

  for (int i = 0; i < node->nodes.size(); ++i) {    
    perms(node->nodes[i], res, perm);
  }

  if (!node->nodes.size()) {
    res.push_back(perm);
  }

  if (perm.size()) {
    perm.pop_back();
  }
  
  return;
}

void PMTree::permNumber(Node* node, std::vector<char>& res, int num) {
  if (!node->nodes.size()) {
    return;
  }

  int fact = 1;
  for (int n = node->nodes.size() - 1; n != 0; n--) {
    fact *= n;
  }

  int i = num / fact;
  num %= fact;

  res.push_back(node->nodes[i]->data);
  permNumber(node->nodes[i], res, num);
}

void PMTree::create(std::vector<char>& data) {
  create_tree(nullptr, data);
}

void PMTree::getPerms(std::vector<std::vector<char>>& res) {
  std::vector<char> perm;
  perms(root, res, perm);
}

void PMTree::getPermNumber(std::vector<char>& res, int num) {
  int fact = 1;
  for (int n = root->nodes.size(); n != 0; n--) {
    fact *= n;
  }

  if (num > fact || num <= 0) {
    return;
  }

  permNumber(root, res, num-1);
}

std::vector<std::vector<char>> getAllPerms(PMTree& tree) {
  std::vector<std::vector<char>> result;
  tree.getPerms(result);
  return result;
}

std::vector<char> getPerm1(PMTree& tree, int num) {
  std::vector<std::vector<char>> perms = getAllPerms(tree);
  return perms[num - 1];
}

std::vector<char> getPerm2(PMTree& tree, int num) {
  std::vector<char> res;
  tree.getPermNumber(res, num);
  return res;
}
