#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    if (nums.size() == 1) return nums[0];
    map<int, int> counts;
    for (auto i : nums) ++counts[i];
    int N = counts.size();
    vector<int> ns, val;
    ns.reserve(N);
    val.reserve(N);
    for (auto& i : counts) {
      ns.push_back(i.first);
      val.push_back(i.first * i.second);
    }
    vector<int> dp(N);
    dp[0] = val[0];
    dp[1] = ns[1] - 1 != ns[0] ? val[0] + val[1] : max(val[0], val[1]);
    for (int i = 2; i < N; ++i)
      dp[i] = ns[i] - 1 != ns[i - 1] ? dp[i - 1] + val[i] : max(dp[i - 2] + val[i], dp[i - 1]);
    return dp.back();
  }
};
// @lc code=end
