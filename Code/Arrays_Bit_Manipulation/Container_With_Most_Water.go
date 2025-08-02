package main

import (
    "fmt"
)

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

func main() {
    height := []int{1, 8, 6, 2, 5, 4, 8, 3, 7}
    fmt.Println("Maximum water that can be contained:", maxArea(height))
}
