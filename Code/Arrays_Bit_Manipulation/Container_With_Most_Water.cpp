class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int heightMin = min(height[left], height[right]);
            int width = right - left;
            int currentArea = heightMin * width;
            maxWater = max(maxWater, currentArea);

            if (height[left] < height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxWater;
    }
};
