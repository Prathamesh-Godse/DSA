/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let left = 0, right = height.length - 1;
    let maxWater = 0;

    while (left < right) {
        let h = Math.min(height[left], height[right]);
        let w = right - left;
        let area = h * w;
        maxWater = Math.max(maxWater, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
};

// Test case
const height = [1, 8, 6, 2, 5, 4, 8, 3, 7];
const result = maxArea(height);
console.log("Maximum water that can be contained:", result);
