#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T>
void print_matrix(const vector<vector<T>>& mat) {
  for (size_t i = 0; i < mat.size(); ++i) {
    for (size_t j = 0; j < mat[0].size(); ++j) cout << mat[i][j] << "\t";
    cout << endl;
  }
}

const int MAX_INT = numeric_limits<int>::max();
const int null = MAX_INT;

struct TreeNode {
  int val;
  TreeNode* left{nullptr};
  TreeNode* right{nullptr};
  TreeNode(int x) : val(x) {}
};

TreeNode* build_tree(const vector<int>& vals) {
  auto root = new TreeNode(vals[0]);

  queue<TreeNode*> q;
  q.push(root);
  int i = 0;
  while (!q.empty() && i < vals.size()) {
    if (vals[++i] != MAX_INT) {
      q.front()->left = new TreeNode(vals[i]);
      q.push(q.front()->left);
    }
    if (vals[++i] != MAX_INT) {
      q.front()->right = new TreeNode(vals[i]);
      q.push(q.front()->right);
    }
    q.pop();
  }

  return root;
}