#ifndef BINARYTREE_H
#define BINARYTREE_H

#pragma once
#include <QString>
#include <QGraphicsScene>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "nodeshape.h"

using namespace std;

// Теория:
//
// subtree - поддерево (является деревом, но корень может иметь родителя, или не иметь вовсе)
//
// root - корень дерева (не имеет родителя, имеет потомков)
// node - промежуточный узел дерева (имеет родителя, имеет потомков)
// leaf - лист дерева (имеет родителя, не имеет потомков)
//
// Пример:
//
// Binary Search Tree:
//
//				root
//			  /      \
//			leaf	node
//				   /    \
//				 leaf  leaf
//
// Binary Subtree:
//
//				root				node			leaf
//			  /      \			   /	\
//			leaf	node		 leaf  leaf
//				   /    \
//				 leaf  leaf
//
// Проходы:
// Прямой		(	действие;		левая ветвь;	правая ветвь;	)
// Симметричный (	левая ветвь;	действие;		правая ветвь;	)
// Обратный		(	левая ветвь;	правая ветвь;	действие;		)
//
// Пример:
//
// 				 20
//			  /      \
//			 10	     30
//				   /    \
//				  25    35
//
// Прямой обход: 20 10 30 25 35
// Симметричный обход: 10 20 25 30 35
// Обратный обход: 10 25 35 30 20
//
// Дерево содержит только уникальные значения
//
// Сбалансированное бинарно дерево требует условия одинакового или различно на один количества узлов левой и правой ветки. Условие выполняется для каждого поддерева
// Пример:
//
// Binary Search Tree:
//
// 				 20
//			  /      \
//			 10	     30
//				   /    \
//				  25    35
//
// Balanced Binary Search Tree:
//
// 				 25
//			   /    \
//			 20	     30
//			/	       \
//		   10			35
//

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val);
};

class BinaryTree
{
protected:
    Node* root;
    NodeShape* nodeshape;

    bool is_empty();
    void _clear(Node* leaf);

    int _depth(Node* leaf);
    void _visualise(Node*& leaf, int leaf_number, QGraphicsScene *scene, int mode);

    QString _forward(Node* node);
    QString _symmetric(Node* node);
    QString _reverse(Node* node);

    virtual bool _insert(Node*& node, int& val) = 0;
    virtual Node*& _remove(Node*& node, int& key) = 0;
    virtual bool _contains(Node*& node, int& key) = 0;

    vector<int> _make_vector(Node*& node);
    Node* _make_balanced(vector<int> vals, int start, int end);


public:
    BinaryTree();
    BinaryTree(Node& node);
    ~BinaryTree();

    void clear();
    QString print(short choice);

    void visualise(QGraphicsScene *scene, int mode);

    virtual bool insert(int& val) = 0;
    virtual Node*& remove(int& key) = 0;
    virtual bool contains(int& key) = 0;

    Node* balance();
};

#endif // BINARYTREE_H
