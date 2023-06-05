#include "searchtree.h"

bool SearchTree::_insert(Node*& node, int& val)
{
    bool added = false;
    if (node == nullptr)
    {
        node = new Node(val);
        added = true;
    }
    else
    {
        if (val < node->data)
        {
            added = _insert(node->left, val);
        }
        else if (val > node->data)
        {
            added = _insert(node->right, val);
        }
        else
        {
            added = false;
        }
    }
    return added;
}

Node*& SearchTree::_remove(Node*& node, int& key)
{
    removed = nullptr;
    if (node != nullptr)
    {
        if (node->data == key)
        {
            if (node->left == nullptr and node->right == nullptr)
            {
                removed = node;
                node = nullptr;
            }
            else if (node->left != nullptr and node->right == nullptr)
            {
                removed = node;
                node = node->left;
            }
            else if (node->left == nullptr and node->right != nullptr)
            {
                removed = node;
                node = node->right;
            }
            else if (node->left != nullptr and node->right != nullptr)
            {
                Node*& minimum = _min(node->right);
                node->data = minimum->data;
                minimum->data = key;
                removed = _remove(minimum, minimum->data);
            }
        }
        else
        {
            if (key < node->data)
            {
                removed = _remove(node->left, key);
            }
            else
            {
                removed = _remove(node->right, key);
            }
        }
    }
    return removed;
}

Node*& SearchTree::_min(Node*& node)
{
    minimum = nullptr;
    if (node != nullptr)
    {
        if (node->left == nullptr)
        {
            minimum = node;
        }
        else
        {
            minimum = _min(node->left);
        }
    }
    return minimum;
}

bool SearchTree::_contains(Node*& node, int& key)
{
    bool exists = false;
    if (node != nullptr)
    {
        if (key < node->data)
        {
            exists = _contains(node->left, key);
        }
        else if (key > node->data)
        {
            exists = _contains(node->right, key);
        }
        else
        {
            exists = true;
        }
    }
    return exists;
}

SearchTree::SearchTree() : BinaryTree() {}

SearchTree::SearchTree(Node& node) : BinaryTree(node) {}

SearchTree::~SearchTree() {}

bool SearchTree::insert(int& val)
{
    return _insert(root, val);
}

Node*& SearchTree::remove(int& key)
{
    return _remove(root, key);
}

bool SearchTree::contains(int& key)
{
    return _contains(root, key);
}
