function subarraysDivByK(nums, k) {
    const remainderCount = new Map();
    remainderCount.set(0, 1);

    let prefixSum = 0, count = 0;

    for (let num of nums) {
        prefixSum += num;
        let remainder = ((prefixSum % k) + k) % k; // handle negative mods

        count += remainderCount.get(remainder) || 0;
        remainderCount.set(remainder, (remainderCount.get(remainder) || 0) + 1);
    }

    return count;
}

// Test
const nums = [4, 5, 0, -2, -3, 1];
const k = 5;
console.log(`Number of subarrays divisible by ${k} is: ${subarraysDivByK(nums, k)}`);
