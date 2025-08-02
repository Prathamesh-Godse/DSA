using System;
using System.Collections.Generic;

public class Solution {
    public int SubarraysDivByK(int[] nums, int k) {
        var remainderCount = new Dictionary<int, int>();
        remainderCount[0] = 1;

        int prefixSum = 0, count = 0;

        foreach (int num in nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k;

            if (remainderCount.ContainsKey(remainder)) {
                count += remainderCount[remainder];
                remainderCount[remainder]++;
            } else {
                remainderCount[remainder] = 1;
            }
        }

        return count;
    }
}

public class Program {
    public static void Main(string[] args) {
        var sol = new Solution();
        int[] nums = { 4, 5, 0, -2, -3, 1 };
        int k = 5;

        int result = sol.SubarraysDivByK(nums, k);
        Console.WriteLine($"Number of subarrays divisible by {k} is: {result}");
    }
}
