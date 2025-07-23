// Problem: Container With Most Water
// LeetCode: https://leetcode.com/problems/container-with-most-water/
// Category: Two Pointers, Array
// Difficulty: Medium

/*
You are given an integer array `height` of length n. 
Each element `height[i]` represents a vertical line at the coordinate (i, height[i]).

You must find two lines that together with the x-axis form a container, 
such that the container contains the most water.

Return the maximum amount of water a container can store.

Water contained = min(height[i], height[j]) * (j - i)
*/

/*
Example:

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The lines at index 1 and 8 form the container with max area: 
min(8, 7) * (8 - 1) = 7 * 7 = 49
*/

// Approach: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                res = max(res, min(heights[i], heights[j]) * (j - i));
            }
        }
        return res;
    }
};


// Approach: Two-Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;
        
        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(res, area);
            
            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};
