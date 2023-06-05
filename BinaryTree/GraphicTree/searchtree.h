#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#pragma once
#include "binarytree.h"

class SearchTree : public BinaryTree
{
private:
    Node* minimum;
    Node* removed;

    bool _insert(Node*& node, int& val) override;
    Node*& _remove(Node*& node, int& key) override;
    Node*& _min(Node*& node);
    bool _contains(Node*& node, int& key) override;

public:
    SearchTree();
    SearchTree(Node& node);
    ~SearchTree();

    bool insert(int& val) override;
    Node*& remove(int& key) override;
    bool contains(int& key) override;
};

#endif // SEARCHTREE_H
