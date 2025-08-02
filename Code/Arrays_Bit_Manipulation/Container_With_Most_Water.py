class Solution:
    def maxArea(self, height):
        left, right = 0, len(height) - 1
        max_water = 0
        while left < right:
            h = min(height[left], height[right])
            w = right - left
            max_water = max(max_water, h * w)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_water

# Test case
if __name__ == "__main__":
    sol = Solution()
    height = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    result = sol.maxArea(height)
    print("Maximum water that can be contained:", result)
