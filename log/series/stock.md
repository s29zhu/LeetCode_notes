# [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

```c++
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int min_price = prices[0], max_profit = 0;
    for (auto& i : prices) {
      max_profit = max(max_profit, i - min_price);
      min_price = min(i, min_price);
    }
    return max_profit;
  }
};
```

# [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

```c++
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int pv = 0, profit = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] < prices[i - 1]) {
        if (prices[i - 1] - prices[pv] > 0)
          profit += prices[i - 1] - prices[pv];
        pv = i;
      }
    }
    if (prices.back() - prices[pv] > 0) profit += prices.back() - prices[pv];
    return profit;
  }
};
```

## Optimized

```c++
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i)
        if (prices[i] - prices[i - 1] > 0)
          profit += prices[i] - prices[i - 1];
    return profit;
  }
};
```

# [123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/#/description)

```c++
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();
    if (N == 1) return 0;
    int m = numeric_limits<int>::min() / 2;
    vector<int> h1(N, m), h2(N, m), s1(N, m), s2(N, m);
    h1[0] = -prices[0];
    for (int i = 1; i < N; ++i) {
      h1[i] = max(h1[i - 1], -prices[i]);
      s1[i] = max(s1[i - 1], h1[i - 1] + prices[i]);
      h2[i] = max(h2[i - 1], s1[i - 1] - prices[i]);
      s2[i] = max(s2[i - 1], h2[i - 1] + prices[i]);
    }
    return max({s1.back(), s2.back(), 0});
  }
};
```

# [188. Best Time to Buy and Sell Stock IV](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/#/description)

```c++
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    int N = prices.size();
    if (N < 2) return 0;
    int m = numeric_limits<int>::min() / 2;
    vector<vector<int>> h(N, vector<int>(k, m)), s(N, vector<int>(k, m));
    h[0][0] = -prices[0];
    for (int i = 1; i < N; ++i) {
      h[i][0] = max(h[i - 1][0], -prices[i]);
      s[i][0] = max(s[i - 1][0], max(h[i - 1][0], h[i][0]) + prices[i]);
      for (int j = 1; j < k; ++j) {
        h[i][j] = max(h[i - 1][j], s[i - 1][j - 1] - prices[i]);
        s[i][j] = max(s[i - 1][j], max(h[i - 1][j], h[i][j]) + prices[i]);
      }
    }
    return *max_element(s.back().begin(), s.back().end());
  }
};
```

# [309. Best Time to Buy and Sell Stock with Cooldown](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)

Consider if we sell at (i-2)th day, then we can reduce the problem to a subproblem which starts from (i)th day. So from the end of the vector, we compute the maximum profit start from ith day. The transfer relation relies on whether the stock is bought at the day. So, use v1 stores the maximum profit if to buy at the current day, v2 stores that if not to buy.


```c++
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int N = prices.size();
    vector<int> v1(N + 1, 0), v2(N + 1, 0);
    for (int i = N - 2; i >= 0; --i) {
      v1[i] = max(v1[i + 1] + prices[i + 1] - prices[i], max(v1[i + 2], v2[i + 2]));
      v2[i] = max(v1[i + 1], v2[i + 1]);
    }
    return max(v1[0], v2[0]);
  }
};
```

# [714. Best Time to Buy and Sell Stock with Transaction Fee](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

```c++
class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int N = prices.size();
    if (N == 1) return 0;
    vector<int> hold(N), sold(N);
    hold[0] = -prices[0];
    sold[0] = 0;
    for (int i = 1; i < N; ++i) {
      hold[i] = max(hold[i - 1], sold[i - 1] - prices[i]);
      sold[i] = max(sold[i - 1], hold[i - 1] + prices[i] - fee);
    }
    return sold.back();
  }
};
```

# [Most consistent ways of dealing with the series of stock problems](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75924/Most-consistent-ways-of-dealing-with-the-series-of-stock-problems)

