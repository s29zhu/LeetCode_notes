#include "stl_headers.hpp"

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

/*
 * @lc app=leetcode id=987 lang=cpp
 *
 * [987] Vertical Order Traversal of a Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  using groups = map<int, vector<TreeNode*>>;
  using Rows = unordered_map<TreeNode*, int>;

 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    groups cols;
    Rows rows;
    get_coord(root, 0, 0, rows, cols);
    vector<vector<int>> rst;
    for (auto& i : cols) {
      if (i.second.size() > 1)
        sort(i.second.begin(), i.second.end(), [&rows](auto n1, auto n2) {
          return rows[n1] == rows[n2] ? n1->val < n2->val : rows[n1] < rows[n2];
        });
      rst.emplace_back();
      rst.back().reserve(i.second.size());
      for (auto& j : i.second) rst.back().push_back(j->val);
    }
    return rst;
  }
  void get_coord(TreeNode* root, int row, int col, Rows& rows, groups& cols) {
    if (root) {
      rows[root] = row;
      cols[col].push_back(root);
      get_coord(root->left, row + 1, col - 1, rows, cols);
      get_coord(root->right, row + 1, col + 1, rows, cols);
    }
  }
};
// @lc code=end
