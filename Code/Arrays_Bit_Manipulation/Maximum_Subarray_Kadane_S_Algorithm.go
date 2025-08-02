package main

import (
    "fmt"
)

func maxSubArray(nums []int) int {
    currentSum := nums[0]
    maxSum := nums[0]

    for i := 1; i < len(nums); i++ {
        if nums[i] > currentSum+nums[i] {
            currentSum = nums[i]
        } else {
            currentSum += nums[i]
        }

        if currentSum > maxSum {
            maxSum = currentSum
        }
    }

    return maxSum
}

func main() {
    nums := []int{-2, 1, -3, 4, -1, 2, 1, -5, 4}
    result := maxSubArray(nums)
    fmt.Println("Maximum Subarray Sum:", result)
}
