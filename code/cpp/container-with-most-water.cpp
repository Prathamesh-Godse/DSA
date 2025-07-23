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
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter " << n << " heights:\n";
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    Solution sol;
    int result = sol.maxArea(heights);
    cout << "Maximum area: " << result << endl;
    return 0;
}
