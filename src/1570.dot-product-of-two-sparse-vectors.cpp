#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=1570 lang=cpp
 *
 * [1570] Dot Product of Two Sparse Vectors
 */

// @lc code=start
class SparseVector {
  unordered_map<int, int> data;

 public:
  SparseVector(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] != 0) data[i] = nums[i];
  }

  // Return the dotProduct of two sparse vectors
  int dotProduct(SparseVector& vec) {
    auto& sparser = data.size() < vec.data.size() ? data : vec.data;
    auto& denser = data.size() >= vec.data.size() ? data : vec.data;

    unordered_map<int, int>::iterator it;
    int rst;
    for (auto& i : sparser)
      if ((it = denser.find(i.first)) != denser.end())
        rst += i.second * it->second;
    return rst;
  }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
// @lc code=end
