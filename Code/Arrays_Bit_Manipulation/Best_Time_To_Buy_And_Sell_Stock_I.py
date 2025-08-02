def maxProfit(prices):
    min_price = float('inf')
    max_profit = 0

    for price in prices:
        if price < min_price:
            min_price = price
        elif price - min_price > max_profit:
            max_profit = price - min_price

    return max_profit

if __name__ == "__main__":
    n = int(input("Enter number of days: "))
    prices = list(map(int, input("Enter stock prices: ").split()))
    result = maxProfit(prices)
    print("Maximum profit:", result)
