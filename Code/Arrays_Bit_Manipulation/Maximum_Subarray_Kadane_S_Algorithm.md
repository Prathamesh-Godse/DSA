# Maximum Subarray Kadane's Algorithm

## Leetcode [here](https://leetcode.com/problems/maximum-subarray/description/)

## C++

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

```
[full code](Maximum_Subarray_Kadane_S_Algorithm.cpp)

## Java

```
class Solution {
    public int maxSubArray(int[] nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            currentSum = Math.max(nums[i], currentSum + nums[i]);
            maxSum = Math.max(maxSum, currentSum);
        }

        return maxSum;
    }
}

```
[full code](Maximum_Subarray_Kadane_S_Algorithm.java)

## Python

```
class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        current_sum = max_sum = nums[0]

        for i in range(1, len(nums)):
            current_sum = max(nums[i], current_sum + nums[i])
            max_sum = max(max_sum, current_sum)

        return max_sum

```
[full code](Maximum_Subarray_Kadane_S_Algorithm.py)

## C

```
int maxSubArray(int* nums, int numsSize) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (currentSum + nums[i] > nums[i])
            currentSum = currentSum + nums[i];
        else
            currentSum = nums[i];

        if (currentSum > maxSum)
            maxSum = currentSum;
    }

    return maxSum;
}

```
[full code](Maximum_Subarray_Kadane_S_Algorithm.c)

## C#

```
public class Solution {
    public int MaxSubArray(int[] nums) {
        int currentSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.Length; i++) {
            currentSum = Math.Max(nums[i], currentSum + nums[i]);
            maxSum = Math.Max(maxSum, currentSum);
        }

        return maxSum;
    }
}

```
[full code](Maximum_Subarray_Kadane_S_Algorithm.cs)

## JavaScript

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let currentSum = nums[0];
    let maxSum = nums[0];

    for (let i = 1; i < nums.length; i++) {
        currentSum = Math.max(nums[i], currentSum + nums[i]);
        maxSum = Math.max(maxSum, currentSum);
    }

    return maxSum;
};

```
[full code](Maximum_Subarray_Kadane_S_Algorithm.js)

## PHP

```
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maxSubArray($nums) {
        $currentSum = $nums[0];
        $maxSum = $nums[0];

        for ($i = 1; $i < count($nums); $i++) {
            $currentSum = max($nums[$i], $currentSum + $nums[$i]);
            $maxSum = max($maxSum, $currentSum);
        }

        return $maxSum;
    }
}

```
[full code](Maximum_Subarray_Kadane_S_Algorithm.php)

## Go

```
func maxSubArray(nums []int) int {
    currentSum := nums[0]
    maxSum := nums[0]

    for i := 1; i < len(nums); i++ {
        if nums[i] > currentSum+nums[i] {
            currentSum = nums[i]
        } else {
            currentSum += nums[i]
        }

        if currentSum > maxSum {
            maxSum = currentSum
        }
    }

    return maxSum
}

```
[full code](Maximum_Subarray_Kadane_S_Algorithm.go)
