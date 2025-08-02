package main

import (
    "fmt"
)

func subarraysDivByK(nums []int, k int) int {
    remainderCount := make(map[int]int)
    remainderCount[0] = 1

    prefixSum := 0
    count := 0

    for _, num := range nums {
        prefixSum += num
        remainder := ((prefixSum % k) + k) % k // handle negative mod

        count += remainderCount[remainder]
        remainderCount[remainder]++
    }

    return count
}

func main() {
    nums := []int{4, 5, 0, -2, -3, 1}
    k := 5
    result := subarraysDivByK(nums, k)
    fmt.Printf("Number of subarrays divisible by %d is: %d\n", k, result)
}
