#include "stl_headers.hpp"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start

class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head) {
    vector<ListNode *> nodes{head};
    while (nodes.back()->next) nodes.push_back(nodes.back()->next);
    return buildTree(nodes, 0, nodes.size() - 1);
  }
  TreeNode *buildTree(vector<ListNode *> &nodes, int start, int end) {
    if (start > end) return nullptr;
    if (start == end) return new TreeNode(nodes[start]->val);
    int m = (start + end) / 2;
    return new TreeNode(nodes[m]->val, buildTree(nodes, start, m - 1),
                        buildTree(nodes, m + 1, end));
  }
};
// @lc code=end
