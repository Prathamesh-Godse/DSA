using System;

public class Solution {
    public int MaxArea(int[] height) {
        int left = 0, right = height.Length - 1;
        int maxWater = 0;

        while (left < right) {
            int h = Math.Min(height[left], height[right]);
            int w = right - left;
            int area = h * w;
            maxWater = Math.Max(maxWater, area);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return maxWater;
    }
}

class Program {
    static void Main(string[] args) {
        Solution sol = new Solution();
        int[] height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
        int result = sol.MaxArea(height);
        Console.WriteLine("Maximum water that can be contained: " + result);
    }
}
