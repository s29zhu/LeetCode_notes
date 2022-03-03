#include "stl_headers.hpp"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * @lc app=leetcode id=863 lang=cpp
 *
 * [863] All Nodes Distance K in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  using Map = unordered_map<TreeNode*, TreeNode*>;

 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    Map parent;
    lineage(root, target, parent);
    vector<int> rst;
    descendent_k(target, nullptr, k, rst);

    auto q = target;
    for (int i = k - 1; i >= 0; --i) {
      if (parent.find(q) == parent.end()) break;
      auto p = parent[q];
      descendent_k(p, q, i, rst);
      q = p;
    }
    return rst;
  }

  void descendent_k(TreeNode* root, TreeNode* exclude, int k,
                    vector<int>& rst) {
    if (!root || root == exclude) return;
    if (k == 0)
      rst.push_back(root->val);
    else {
      descendent_k(root->left, exclude, k - 1, rst);
      descendent_k(root->right, exclude, k - 1, rst);
    }
  }

  void lineage(TreeNode* root, TreeNode* target, Map& parent) {
    if (root == target) return;
    for (auto& i : {root->left, root->right}) {
      if (!i) continue;
      parent[i] = root;
      lineage(i, target, parent);
    }
  }
};
// @lc code=end
