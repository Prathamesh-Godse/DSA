public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int result = sol.maxArea(height);
        System.out.println("Maximum water that can be contained: " + result);
    }
}

class Solution {
    public int maxArea(int[] height) {
        int left = 0, right = height.length - 1;
        int maxWater = 0;
        while (left < right) {
            int h = Math.min(height[left], height[right]);
            int w = right - left;
            maxWater = Math.max(maxWater, h * w);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxWater;
    }
}
