import java.util.*;

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {4, 5, 0, -2, -3, 1};
        int k = 5;

        int result = sol.subarraysDivByK(nums, k);
        System.out.println("Number of subarrays divisible by " + k + " is: " + result);
    }
}

class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> remainderCount = new HashMap<>();
        remainderCount.put(0, 1);

        int prefixSum = 0, count = 0;

        for (int num : nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k;

            count += remainderCount.getOrDefault(remainder, 0);
            remainderCount.put(remainder, remainderCount.getOrDefault(remainder, 0) + 1);
        }

        return count;
    }
}
