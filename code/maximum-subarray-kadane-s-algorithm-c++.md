# Maximum Subarray-Kadane's Algorithm

## Brute Force

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), res = nums[0];
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = i; j < n; j++) {
                cur += nums[j];
                res = max(res, cur);
            }
        }
        return res;
    }
};
```

## Recursion

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return dfs(nums, 0, false);
    }

private:
    int dfs(vector<int>& nums, int i, bool flag) {
        if (i == nums.size()) return flag ? 0 : -1e6;
        if (flag) return max(0, nums[i] + dfs(nums, i + 1, true));
        return max(dfs(nums, i + 1, false), 
                   nums[i] + dfs(nums, i + 1, true));
    }
};
```

## Dynamic Programming (Top-Down)

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<vector<int>> memo(nums.size() + 1, vector<int>(2, INT_MIN));
        return dfs(nums, 0, false, memo);
    }
    
private:
    int dfs(vector<int>& nums, int i, bool flag, vector<vector<int>>& memo) {
        if (i == nums.size()) return flag ? 0 : -1e6;
        int f = flag ? 1 : 0;
        if (memo[i][f] != INT_MIN) return memo[i][f];
        if (flag)
            memo[i][f] = max(0, nums[i] + dfs(nums, i + 1, true, memo));
        else
            memo[i][f] = max(dfs(nums, i + 1, false, memo), 
                             nums[i] + dfs(nums, i + 1, true, memo));
        return memo[i][f];
    }
};
```

## Dynamic Programming (Bottom-Up)

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        
        dp[n - 1][1] = dp[n - 1][0] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            dp[i][1] = max(nums[i], nums[i] + dp[i + 1][1]);
            dp[i][0] = max(dp[i + 1][0], dp[i][1]);
        }
        
        return dp[0][0];
    }
};
```

## Dynamic Programming (Space Optimized)

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums);
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
```

## Kadane's Algorithm

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0], curSum = 0;
        for (int num : nums) {
            if (curSum < 0) {
                curSum = 0;
            }
            curSum += num;
            maxSub = max(maxSub, curSum);
        }
        return maxSub;
    }
};
```

## Divide & Conquer

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

private:
    int dfs(vector<int>& nums, int l, int r) {
        if (l > r) {
            return INT_MIN;
        }
        int m = (l + r) >> 1;
        int leftSum = 0, rightSum = 0, curSum = 0;
        for (int i = m - 1; i >= l; --i) {
            curSum += nums[i];
            leftSum = max(leftSum, curSum);
        }
        curSum = 0;
        for (int i = m + 1; i <= r; ++i) {
            curSum += nums[i];
            rightSum = max(rightSum, curSum);
        }
        return max(dfs(nums, l, m - 1), 
                   max(dfs(nums, m + 1, r), 
                       leftSum + nums[m] + rightSum));
    }
};
```
