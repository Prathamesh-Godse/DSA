# Best Time To Buy And Sell Stock I

## Leetcode [here](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

## C++

```
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

```
[full code](Best_Time_To_Buy_And_Sell_Stock_I.cpp)

## Java

```
class Solution {
    public int maxProfit(int[] prices) {
        int minPrice = Integer.MAX_VALUE;
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
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_I.java)

## Python

```
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        min_price = float('inf')
        max_profit = 0

        for price in prices:
            if price < min_price:
                min_price = price
            elif price - min_price > max_profit:
                max_profit = price - min_price

        return max_profit

```
[full code](Best_Time_To_Buy_And_Sell_Stock_I.py)

## C

```
int maxProfit(int* prices, int pricesSize) {
    int minPrice = __INT_MAX__;
    int maxProfit = 0;

    for (int i = 0; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }

    return maxProfit;
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_I.c)

## C#

```
public class Solution {
    public int MaxProfit(int[] prices) {
        int minPrice = int.MaxValue;
        int maxProfit = 0;

        foreach (int price in prices) {
            if (price < minPrice) {
                minPrice = price;
            } else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }

        return maxProfit;
    }
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_I.cs)

## JavaScript

```
var maxProfit = function(prices) {
    let minPrice = Infinity;
    let maxProfit = 0;

    for (let price of prices) {
        if (price < minPrice) {
            minPrice = price;
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice;
        }
    }

    return maxProfit;
};

```
[full code](Best_Time_To_Buy_And_Sell_Stock_I.js)

## PHP

```
class Solution {
    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $minPrice = PHP_INT_MAX;
        $maxProfit = 0;

        foreach ($prices as $price) {
            if ($price < $minPrice) {
                $minPrice = $price;
            } else if ($price - $minPrice > $maxProfit) {
                $maxProfit = $price - $minPrice;
            }
        }

        return $maxProfit;
    }
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_I.php)

## Go

```
func maxProfit(prices []int) int {
    minPrice := int(^uint(0) >> 1) // Max int
    maxProfit := 0

    for _, price := range prices {
        if price < minPrice {
            minPrice = price
        } else if price - minPrice > maxProfit {
            maxProfit = price - minPrice
        }
    }

    return maxProfit
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_I.go)

---

# Best Time To Buy And Sell Stock II

## Leetcode [here](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)

## C++

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};

```
[full code](Best_Time_To_Buy_And_Sell_Stock_II.cpp)

## Java

```
class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        for(int i = 1; i < prices.length; i++) {
            if(prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_II.java)

## Python

```
class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profit = 0
        for i in range(1, len(prices)):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]
        return profit

```
[full code](Best_Time_To_Buy_And_Sell_Stock_II.py)

## C

```
int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    for(int i = 1; i < pricesSize; i++) {
        if(prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_II.c)

## C#

```
public class Solution {
    public int MaxProfit(int[] prices) {
        int profit = 0;
        for (int i = 1; i < prices.Length; i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_II.cs)

## JavaScript

```
var maxProfit = function(prices) {
    let profit = 0;
    for (let i = 1; i < prices.length; i++) {
        if (prices[i] > prices[i - 1]) {
            profit += prices[i] - prices[i - 1];
        }
    }
    return profit;
};

```
[full code](Best_Time_To_Buy_And_Sell_Stock_II.js)

## PHP

```
class Solution {
    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $profit = 0;
        for ($i = 1; $i < count($prices); $i++) {
            if ($prices[$i] > $prices[$i - 1]) {
                $profit += $prices[$i] - $prices[$i - 1];
            }
        }
        return $profit;
    }
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_II.php)

## Go

```
func maxProfit(prices []int) int {
    profit := 0
    for i := 1; i < len(prices); i++ {
        if prices[i] > prices[i-1] {
            profit += prices[i] - prices[i-1]
        }
    }
    return profit
}

```
[full code](Best_Time_To_Buy_And_Sell_Stock_II.go)
