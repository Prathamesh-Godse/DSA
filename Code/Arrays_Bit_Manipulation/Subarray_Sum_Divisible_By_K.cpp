#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;

        int prefixSum = 0, count = 0;

        for (int num : nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k;

            if (remainderCount.count(remainder)) {
                count += remainderCount[remainder];
            }
            remainderCount[remainder]++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    int k = 5;

    int result = sol.subarraysDivByK(nums, k);
    cout << "Number of subarrays divisible by " << k << " is: " << result << endl;

    return 0;
}
