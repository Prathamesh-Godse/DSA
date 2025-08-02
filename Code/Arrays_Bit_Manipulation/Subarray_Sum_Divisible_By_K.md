# Subarray Sum Divisible By K

## Leetcode [here]()

## C++

```
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;

        int prefixSum = 0, count = 0;

        for (int num : nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k; // handle negative mods

            if (remainderCount.count(remainder)) {
                count += remainderCount[remainder];
            }
            remainderCount[remainder]++;
        }

        return count;
    }
};

```
[full code](Subarray_Sum_Divisible_By_K.cpp)

## Java

```
class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        Map<Integer, Integer> remainderCount = new HashMap<>();
        remainderCount.put(0, 1);

        int prefixSum = 0, count = 0;

        for (int num : nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k;

            count += remainderCount.getOrDefault(remainder, 0);
            remainderCount.put(remainder, remainderCount.getOrDefault(remainder, 0) + 1);
        }

        return count;
    }
}

```
[full code](Subarray_Sum_Divisible_By_K.java)

## Python

```
class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        from collections import defaultdict
        
        remainder_count = defaultdict(int)
        remainder_count[0] = 1

        prefix_sum = 0
        count = 0

        for num in nums:
            prefix_sum += num
            remainder = (prefix_sum % k + k) % k  # Handle negative remainders
            count += remainder_count[remainder]
            remainder_count[remainder] += 1

        return count

```
[full code](Subarray_Sum_Divisible_By_K.py)

## C

```
int subarraysDivByK(int* nums, int numsSize, int k) {
    int* modCount = (int*)calloc(k, sizeof(int));
    modCount[0] = 1;  // Initial prefix sum % k = 0

    int prefixSum = 0;
    int count = 0;

    for (int i = 0; i < numsSize; ++i) {
        prefixSum += nums[i];
        int mod = ((prefixSum % k) + k) % k; // handle negatives

        count += modCount[mod];
        modCount[mod]++;
    }

    free(modCount);
    return count;
}
```
[full code](Subarray_Sum_Divisible_By_K.c)

## C#

```
public class Solution {
    public int SubarraysDivByK(int[] nums, int k) {
        var remainderCount = new Dictionary<int, int>();
        remainderCount[0] = 1;

        int prefixSum = 0, count = 0;

        foreach (int num in nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k;

            if (remainderCount.ContainsKey(remainder)) {
                count += remainderCount[remainder];
                remainderCount[remainder]++;
            } else {
                remainderCount[remainder] = 1;
            }
        }

        return count;
    }
}

```
[full code](Subarray_Sum_Divisible_By_K.cs)

## JavaScript

```
var subarraysDivByK = function(nums, k) {
    const remainderCount = new Map();
    remainderCount.set(0, 1);

    let prefixSum = 0, count = 0;

    for (let num of nums) {
        prefixSum += num;
        let remainder = ((prefixSum % k) + k) % k;

        count += remainderCount.get(remainder) || 0;
        remainderCount.set(remainder, (remainderCount.get(remainder) || 0) + 1);
    }

    return count;
};

```
[full code](Subarray_Sum_Divisible_By_K.js)

## PHP

```
class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Integer
     */
    function subarraysDivByK($nums, $k) {
        $remainderCount = [];
        $remainderCount[0] = 1;

        $prefixSum = 0;
        $count = 0;

        foreach ($nums as $num) {
            $prefixSum += $num;
            $remainder = (($prefixSum % $k) + $k) % $k;

            if (isset($remainderCount[$remainder])) {
                $count += $remainderCount[$remainder];
            }
            $remainderCount[$remainder] = ($remainderCount[$remainder] ?? 0) + 1;
        }

        return $count;
    }
}

```
[full code](Subarray_Sum_Divisible_By_K.php)

## Go

```
func subarraysDivByK(nums []int, k int) int {
    remainderCount := make(map[int]int)
    remainderCount[0] = 1

    prefixSum := 0
    count := 0

    for _, num := range nums {
        prefixSum += num
        remainder := ((prefixSum % k) + k) % k

        count += remainderCount[remainder]
        remainderCount[remainder]++
    }

    return count
}

```
[full code](Subarray_Sum_Divisible_By_K.go)
