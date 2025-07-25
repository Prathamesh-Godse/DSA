class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> modCount;
        modCount[0] = 1;  // Subarray starting from index 0
        int sum = 0, count = 0;

        for (int num : nums) {
            sum += num;
            int mod = ((sum % k) + k) % k;  // ensure mod is positive

            if (modCount.count(mod)) {
                count += modCount[mod];
            }

            modCount[mod]++;
        }

        return count;
    }
};
