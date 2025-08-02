#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    for(int i = 1; i < pricesSize; i++) {
        if(prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(prices[0]);
    int result = maxProfit(prices, size);
    printf("Max Profit: %d\n", result);
    return 0;
}
