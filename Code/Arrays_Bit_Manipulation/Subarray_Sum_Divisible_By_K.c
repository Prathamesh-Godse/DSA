#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    int nums[] = {4, 5, 0, -2, -3, 1};
    int k = 5;
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = subarraysDivByK(nums, size, k);
    printf("Number of subarrays divisible by %d is: %d\n", k, result);
    return 0;
}
