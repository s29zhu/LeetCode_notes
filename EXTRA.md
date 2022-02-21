## [1945. Sum of Digits of String After Convert](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/)

```c++
class Solution {
 public:
  int getLucky(string s, int k) {
    vector<int> digits = move(convert_digits(s));
    int rst = accumulate(digits.begin(), digits.end(), 0);
    for (int i = 1; i < k; ++i) rst = sum_digits(rst);
    return rst;
  }
  int sum_digits(int a) {
    int s = 0;
    for (int i = 1; i <= a; i *= 10) s += (a / i) % 10;
    return s;
  }
  vector<int> convert_digits(const string& s) {
    vector<int> rst;
    rst.reserve(s.size() * 2);
    for (auto& i : s) {
      if (i >= 't') {
        rst.push_back(2);
        rst.push_back(i - 't');
      } else if (i >= 'j') {
        rst.push_back(1);
        rst.push_back(i - 'j');
      } else {
        rst.push_back(i - 'a' + 1);
      }
    }
    rst.shrink_to_fit();
    return rst;
  }
};
```

## [1818. Minimum Absolute Sum Difference](https://leetcode.com/problems/minimum-absolute-sum-difference/)

```c++
class Solution {
 public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    vector<int> s = nums1;
    sort(s.begin(), s.end());
    long max_dec = 0, sum = 0;
    for (int i = 0; i < nums2.size(); ++i) {
      long ss = abs(nums2[i] - nums1[i]);
      if (ss > max_dec) {
        long dec = ss - abs(nums2[i] - nearest(s, nums2[i]));
        if (dec > max_dec) max_dec = dec;
      }
      sum += ss;
    }
    return (sum - max_dec) % 1000000007;
  }
  int nearest(const vector<int>& s, int q) {
    if (q <= s.front()) return s.front();
    if (q >= s.back()) return s.back();

    int low = 0, high = s.size() - 1, mid = (low + high) / 2;
    while (low != mid) {
      if (q == s[mid]) return q;
      if (q > s[mid]) low = mid;
      else high = mid;
      mid = (low + high) / 2;
    }
    return abs(q - s[low]) < abs(s[high] - q) ? s[low] : s[high];
  }
};
```

> Note: for each element, before computing the potential decrease of the difference, check if the current difference is lower than the maximum decrease. If the existing difference is lower than the maximum decrease, we don't need to bother whether it can have a larger decrease.

## [1137. N-th Tribonacci Number](https://leetcode.com/problems/n-th-tribonacci-number/description/)

### Space O(1)

```c++
class Solution {
 public:
  int tribonacci(int n) {
    array<int, 4> a{0, 1, 1, 2};
    if (n < 4) return a[n];
    for (int i = 3; i < n; ++i) {
      a[0] = a[1];
      a[1] = a[2];
      a[2] = a[3];
      a[3] = a[0] + a[1] + a[2];
    }
    return a[3];
  }
};
```

### More compact

```c++
class Solution {
 public:
  int tribonacci(int n) {
    array<int, 3> a{0, 1, 1};
    for (int i = 3; i <= n; ++i)
      a[i % 3] = a[(i - 1) % 3] + a[(i - 2) % 3] + a[i % 3];
    return a[n % 3];
  }
};
```

## [746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/)

Compute the minimum cost for stepping on ith stair.

```c++
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    array<int, 2> a{cost[0], cost[1]};
    for (int i = 2; i < cost.size(); ++i)
      a[i % 2] = min(a[i % 2], a[(i - 1) % 2]) + cost[i];
    return min(a[0], a[1]);
  }
};
```

## [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

```c++
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (int i = m - 1, j = n - 1, k = m + n - 1; k >= 0; --k)
      if (j < 0 && i >= 0)
        nums1[k] = nums1[i--];
      else if (i < 0 && j >= 0)
        nums1[k] = nums2[j--];
      else if (nums1[i] > nums2[j])
        nums1[k] = nums1[i--];
      else
        nums1[k] = nums2[j--];    
  }
};
```

## [740. Delete and Earn](https://leetcode.com/problems/delete-and-earn/)

[Similar: House Robber](2022-01-23.md#198-house-robber)

```c++
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
```

## [55. Jump Game](https://leetcode.com/problems/jump-game/)

### Simple simulation

Time: O(N^2), Space: O(N)

Equivalent to BFS. Each number v in the nums gives v edges.

```c++
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int N = nums.size();
    vector<bool> v(N, false);
    v[0] = true;
    for (int i = 0; i < N; ++i)
      if (v[i])
        for (int j = i + 1; j <= nums[i] + i; ++j)
          if (j < N - 1)
            v[j] = true;
          else
            return true;
    return v.back();
  }
};
```

### Optimized

Since we can choose jump [1 ~ N] steps if we stand on a N, the squares can be reached are consecutive. So we can just focus on the furthest index which indicates all the indices less than it are reachable.

```c++
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    for (int i = 0, max_i = nums[0], N = nums.size(); i < N && i <= max_i; ++i)
      if ((max_i = max(max_i, nums[i] + i)) >= N - 1) return true;
    return false;
  }
};
```

**Why is this slower than the following solution?**

### Reversed DP in Solution

```c++
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int j = nums.size() - 1;
    for (int i = j; i >= 0; i--)
      if (i + nums[i] >= j) j = i;
    return j == 0;
  }
};
```

## [45. Jump Game II](https://leetcode.com/problems/jump-game-ii/)

### BFS

```c++
class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = 1, N = nums.size();
    if (N == 1) return 0;
    vector<bool> visited(N, false);
    vector<int> curr_lvl{0};
    while (true) {
      vector<int> next_lvl;
      for (auto i : curr_lvl)
        for (int j = 1; j <= nums[i]; ++j) {
          if (i + j >= N - 1) return n;
          if (visited[i + j]) continue;
          next_lvl.push_back(i + j);
          visited[i + j] = true;
        }
      ++n;
      curr_lvl.swap(next_lvl);
    }
    return -1;
  }
};
```

### Optimized

```c++
class Solution {
 public:
  int jump(vector<int>& nums) {
    int N = nums.size(), n = 1, prev_max = 0, curr_max = nums[0];
    if (N == 1) return 0;
    for (int i = 0; i < N; ++i) {
      if (i > prev_max) {
        prev_max = curr_max;
        ++n;
      }
      int j = i + nums[i];
      if (j >= N - 1) return n;
      if (j > curr_max) curr_max = j;
    }
    return -1;
  }
};
```

## [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)

### Two pointers

1. For left end, discard the [p1, i) if the partial sum becomes less than zero.
2. For right end, discard the (j, P2] if the partial sum becomes less than zero.
3. Move the side on which the partial sum is smaller. This is to avoid the above discarding strategy misses the larger side, e.g. in {1, 2, 3, 4, 5, -100, 6, 7}, if we keep moving left index, the -100 will make the 1~5 looks like not worthy, and we end up with {6, 7}.

```c++
class Solution {
 public:
  int maxSubArray(const vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0];
    int p1 = 0, p2 = N - 1, s1 = nums[p1], s2 = nums[p2];
    int i = p1, j = p2;
    while (i < j) {
      if (s1 < s2) {
        ++i;
        if (s1 < 0) {
          p1 = i;
          s1 = 0;
        }
        if (i != j) s1 += nums[i];
      } else {
        --j;
        if (s2 < 0) {
          p2 = j;
          s2 = 0;
        }
        if (i != j) s2 += nums[j];
      }
    }
    return s1 + s2;
  }
};
```

p1 and p2 can be omitted:
```c++
class Solution {
 public:
  int maxSubArray(const vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0];
    int s1 = nums[0], s2 = nums[N - 1];
    int i = 0, j = N - 1;
    while (i < j) {
      if (s1 < s2) {
        ++i;
        if (s1 < 0) s1 = 0;
        if (i != j) s1 += nums[i];
      } else {
        --j;
        if (s2 < 0) s2 = 0;
        if (i != j) s2 += nums[j];
      }
    }
    return s1 + s2;
  }
};
```

### Dynamic programming

Use a vectoring to keep the maximum sum which can be obtained by selecting the current element as the last.

```c++
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int N = nums.size();
    vector<int> dp(N);

    dp[0] = nums[0];
    int m = nums[0];

    for (int i = 1; i < N; ++i) {
      dp[i] = nums[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
      m = max(m, dp[i]);
    }
    return m;
  }
};
```

The difference between the two methods is the first one always keeps the result optimum, while the second one computes all the partial sums and then compare.


## [918. Maximum Sum Circular Subarray](https://leetcode.com/problems/maximum-sum-circular-subarray/)

Consider two cases:

1. The first and last elements may not be both in the result. Same as [53. Maximum Subarray.](#53-maximum-subarray)
2. The first and last elements are both in the result. This is equivalent to find minimum subarray without considering the first and last elements. Then subtract the partial sum from the total sum.

Compute the maximum for each case, then return the larger one.

```c++
class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0];

    int m1 = nums[0], m2 = nums[1];
    vector<int> v(N, m1);
    for (int i = 1; i < N; ++i) {
      v[i] = nums[i] + (v[i - 1] < 0 ? 0 : v[i - 1]);
      m1 = max(m1, v[i]);
    }
    v[1] = m2;
    for (int i = 2; i < N - 1; ++i) {
      v[i] = nums[i] + (v[i - 1] > 0 ? 0 : v[i - 1]);
      m2 = min(m2, v[i]);
    }
    int s = std::accumulate(nums.begin(), nums.end(), 0);
    return max(m1, s - m2);
  }
};
```


```c++
class Solution {
 public:
  int maxSubarraySumCircular(const vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0];

    int m1 = nums[0], m2 = nums[1];
    array<int, 2> d1{nums[0], 0}, d2{0, nums[1]};
    for (int i = 1; i < N; ++i) {
      int j1 = i % 2, j2 = (i + 1) % 2;
      d1[j1] = nums[i] + (d1[j2] < 0 ? 0 : d1[j2]);
      m1 = max(d1[j1], m1);
      if (i > N - 3) continue;
      d2[j2] = nums[i + 1] + (d2[j1] > 0 ? 0 : d2[j1]);
      m2 = min(d2[j2], m2);
    }
    int s = std::accumulate(nums.begin(), nums.end(), 0);
    return max(m1, s - m2);
  }
};
```

## [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/)

Compute and record both the positive and negative products (maximum abs).

```c++
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0];
    vector<int> vp(N), vn(N);
    vp[0] = nums[0];
    vn[0] = nums[0];
    int max_p = nums[0];
    for (int i = 1; i < N; ++i) {
      if (nums[i] > 0) {
        vp[i] = (vp[i - 1] > 0 ? vp[i - 1] : 1) * nums[i];
        vn[i] = vn[i - 1] * nums[i];
      } else {
        vp[i] = vn[i - 1] * nums[i];
        vn[i] = (vp[i - 1] > 0 ? vp[i - 1] : 1) * nums[i];
      }
      max_p = max(max_p, vp[i]);
    }
    return max_p;
  }
};
```

### Optimized

```c++
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int N = nums.size();
    int pmax = nums[0], pmin = nums[0];
    int m = nums[0];

    for (int i = 1; i < N; ++i) {
      if (nums[i] < 0) swap(pmax, pmin);
      pmax = max(nums[i], pmax * nums[i]);
      pmin = min(nums[i], pmin * nums[i]);
      m = max(m, pmax);
    }
    return m;
  }
};
```

## [1567. Maximum Length of Subarray With Positive Product](https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/description/)

The common idea of the DP with subarray (consecutive): to consider the state if applying the current element, since the consecutive condition requires that the previous one must be applied if the next one is applied. Therefore the transfer relation can be obtained.

```c++
class Solution {
 public:
  int getMaxLen(const vector<int>& nums) {
    int N = nums.size();
    if (N == 1) return nums[0] > 0;
    vector<int> vp(N), vn(N);
    vp[0] = nums[0] > 0;
    vn[0] = nums[0] < 0;
    int m = 0;

    for (int i = 1; i < N; ++i) {
      if (nums[i] > 0) {
        vp[i] = vp[i - 1] + 1;
        vn[i] = vn[i - 1] == 0 ? 0 : vn[i - 1] + 1;
      } else if (nums[i] < 0) {
        vp[i] = vn[i - 1] == 0 ? 0 : vn[i - 1] + 1;
        vn[i] = vp[i - 1] + 1;
      } else {
        vp[i] = 0;
        vn[i] = 0;
      }
      m = max(m, vp[i]);
    }

    return m;
  }
};
```

### Optimized

```c++
class Solution {
 public:
  int getMaxLen(const vector<int>& nums) {
    int N = nums.size();
    int np = nums[0] > 0, nn = nums[0] < 0;
    int m = np;

    for (int i = 1; i < N; ++i) {
      if (nums[i] == 0) {
        np = 0;
        nn = 0;
      } else {
        ++np;
        if (nn != 0) ++nn;
        if (nums[i] < 0) swap(np, nn);
      }
      m = max(m, np);
    }

    return m;
  }
};
```
