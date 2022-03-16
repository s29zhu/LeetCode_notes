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
    unordered_set<int> pp, qq;
    while (p || q) {
      if (p) {
        pp.insert(p->val);
        if (qq.find(p->val) != qq.end()) return p;
        p = p->parent;
      }
      if (q) {
        qq.insert(q->val);
        if (pp.find(q->val) != pp.end()) return q;
        q = q->parent;
      }
    }
    return nullptr;
  }
};
// @lc code=end
