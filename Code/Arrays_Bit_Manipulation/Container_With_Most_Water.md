# Container With Most Water

## Leetcode [here](https://leetcode.com/problems/container-with-most-water/)

## C++

```
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        while (left < right) {
            int h = min(height[left], height[right]);
            int w = right - left;
            maxWater = max(maxWater, h * w);
            if (height[left] < height[right])
                left++;
            else
                right--;
        }
        return maxWater;
    }
};

```
[full code](Container_With_Most_Water.cpp)

## Java

```
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

```

## Python

```
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

```

## C

```
int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxWater = 0;

    while (left < right) {
        int h = height[left] < height[right] ? height[left] : height[right];
        int w = right - left;
        int area = h * w;
        if (area > maxWater)
            maxWater = area;

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
}

```

## C#

```
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
```

## JavaScript

```
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
```

## PHP

```
class Solution {
    /**
     * @param Integer[] $height
     * @return Integer
     */
    function maxArea($height) {
        $left = 0;
        $right = count($height) - 1;
        $maxWater = 0;

        while ($left < $right) {
            $h = min($height[$left], $height[$right]);
            $w = $right - $left;
            $area = $h * $w;
            if ($area > $maxWater) {
                $maxWater = $area;
            }

            if ($height[$left] < $height[$right]) {
                $left++;
            } else {
                $right--;
            }
        }

        return $maxWater;
    }
}
```

## Go

```
func maxArea(height []int) int {
    left, right := 0, len(height)-1
    maxWater := 0

    for left < right {
        h := min(height[left], height[right])
        w := right - left
        area := h * w
        if area > maxWater {
            maxWater = area
        }

        if height[left] < height[right] {
            left++
        } else {
            right--
        }
    }

    return maxWater
}

func min(a, b int) int {
    if a < b {
        return a
    }
    return b
}
```
