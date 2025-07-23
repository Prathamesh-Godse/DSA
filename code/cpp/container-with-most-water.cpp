#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int res = 0;
        for (int i = 0; i < heights.size(); i++) {
            for (int j = i + 1; j < heights.size(); j++) {
                res = max(res, min(heights[i], heights[j]) * (j - i));
            }
        }
        return res;
    }
};

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    int result = sol.maxArea(heights);
    cout << "Maximum area: " << result << endl;
    return 0;
}
