from collections import defaultdict

class Solution:
    def subarraysDivByK(self, nums: list[int], k: int) -> int:
        remainder_count = defaultdict(int)
        remainder_count[0] = 1

        prefix_sum = 0
        count = 0

        for num in nums:
            prefix_sum += num
            remainder = (prefix_sum % k + k) % k
            count += remainder_count[remainder]
            remainder_count[remainder] += 1

        return count

# Test
if __name__ == "__main__":
    sol = Solution()
    nums = [4, 5, 0, -2, -3, 1]
    k = 5
    print("Number of subarrays divisible by", k, "is:", sol.subarraysDivByK(nums, k))
