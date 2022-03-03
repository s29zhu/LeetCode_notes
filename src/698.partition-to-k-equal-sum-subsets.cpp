#include "stl_headers.hpp"

/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start

class Solution {
public:
    bool backtrack(vector<int>& arr, int index, int count, int currSum, int k, 
                   int targetSum, vector<bool>& taken) {
                       
        int n = arr.size();
      
        // We made k - 1 subsets with target sum and last subset will also have target sum.
        if (count == k - 1) { 
            return true;
        }
        
        // No need to proceed further.
        if (currSum > targetSum) { 
            return false;
        }
      
        // When curr sum reaches target then one subset is made.
        // Increment count and reset current sum.
        if (currSum == targetSum) {
            return backtrack(arr, 0, count + 1, 0, k, targetSum, taken);
        }
        
        // Try not picked elements to make some combinations.
        for (int j = index; j < n; ++j) {
            if (taken[j] || index > 0 && arr[j] == arr[index - 1]) continue;
            // Include this element in current subset.
            taken[j] = true;
                
            // If using current jth element in this subset leads to make all valid subsets.
            if (backtrack(arr, j + 1, count, currSum + arr[j], k, targetSum, taken)) {
                return true;
            }
                
            // Backtrack step.
            taken[j] = false;
        } 
      
        // We were not able to make a valid combination after picking each element from the array,
        // hence we can't make k subsets.
        return false;
    }
  
    bool canPartitionKSubsets(vector<int>& arr, int k) {
        int totalArraySum = 0;
        int n = arr.size();
        
        for (int i = 0; i < n; ++i) {
             totalArraySum += arr[i];
        }
      
        // If total sum not divisible by k, we can't make subsets.
        if (totalArraySum % k != 0) { 
            return false;
        }

        // Sort in decreasing order.
        sort(arr.begin(), arr.end(), greater<int>());
      
        int targetSum = totalArraySum / k;
        vector<bool> taken(n, false);
      
        return backtrack(arr, 0, 0, 0, k, targetSum, taken);
    }
};

/* class Solution {
 public:
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    int s = accumulate(nums.begin(), nums.end(), 0);
    if (s % k) return false;
    int ps = s / k;

    map<int, int> counts;
    for (auto i : nums)
      if (i < ps)
        ++counts[i];
      else if (i == ps)
        --k;
      else
        return false;


  }

  bool break_down(int n, map<int, int>& counts) {

  }

}; */
// @lc code=end

int main() {
  Solution s;

  vector<int> arr{1,1,1,1,2,2,2,2};
  int k = 4;

  bool rst = s.canPartitionKSubsets(arr, k);

  return 0;
}
