#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
};

int main() {
    Solution solution;
    vector<int> prices;
    int n, price;

    cout << "Enter number of days: ";
    cin >> n;

    cout << "Enter stock prices for each day:\n";
    for (int i = 0; i < n; ++i) {
        cin >> price;
        prices.push_back(price);
    }

    int result = solution.maxProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}
