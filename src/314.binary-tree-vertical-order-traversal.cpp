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
 * @lc app=leetcode id=314 lang=cpp
 *
 * [314] Binary Tree Vertical Order Traversal
 */

// @lc code=start

class Solution {
  map<int, map<int, vector<int>>> m;
  void search(TreeNode* n, int row, int col) {
    if (!n) return;
    m[col][row].push_back(n->val);
    search(n->left, row + 1, col - 1);
    search(n->right, row + 1, col + 1);
  }

 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    search(root, 0, 0);
    vector<vector<int>> rst;
    for (auto& i : m) {
      rst.emplace_back();
      for (auto& j : i.second)
        rst.back().insert(rst.back().end(), j.second.begin(), j.second.end());
    }
    return rst;
  }
};
// @lc code=end

int main() {
  Solution s;
  // [1, 2, 3, null, 4, 5, null, 6, null, 7, null, null, 8, 9, null, 10, null, null, 11]

  return 0;
}