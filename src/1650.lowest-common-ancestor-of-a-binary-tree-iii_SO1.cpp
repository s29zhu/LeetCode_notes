#include "stl_headers.hpp"

class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* parent;
};

/*
 * @lc app=leetcode id=1650 lang=cpp
 *
 * [1650] Lowest Common Ancestor of a Binary Tree III
 */

// @lc code=start

class Solution {
 public:
  Node* lowestCommonAncestor(Node* p, Node* q) {
    Node *a = p, *b = q;
    while (a != b) {
      a = a ? a->parent : p;
      b = b ? b->parent : q;
    }
    return a;
  }
};
// @lc code=end
