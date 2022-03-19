#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
 public:
  string simplifyPath(string path) {
    vector<array<int, 2>> dirs;
    int i = 1;
    while (i < path.size()) {
      auto p = to_next_slash(path, i);
      if (p[0] == p[1] || p[1] - p[0] == 1 && path[p[0]] == '.') continue;
      if (p[1] - p[0] == 2 && path[p[0]] == '.' && path[p[0] + 1] == '.') {
        if (!dirs.empty()) dirs.pop_back();
      } else {
        dirs.push_back(p);
      }
    }

    string rst;
    for (auto& p : dirs) {
      rst.push_back('/');
      rst.append(path.begin() + p[0], path.begin() + p[1]);
    }
    return rst.empty() ? "/" : rst;
  }

  array<int, 2> to_next_slash(const string& path, int& i) {
    array<int, 2> rst{i, i};
    for (; i < path.size() && path[i] != '/'; ++i) rst[1] = i + 1;
    if (i < path.size()) ++i;
    return rst;
  }
};

// @lc code=end
