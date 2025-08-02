using System;

class Program {
    static int MaxProfit(int[] prices) {
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

    static void Main() {
        Console.Write("Enter number of days: ");
        int n = int.Parse(Console.ReadLine());

        int[] prices = new int[n];
        Console.WriteLine("Enter stock prices:");
        string[] inputs = Console.ReadLine().Split(' ');

        for (int i = 0; i < n; i++) {
            prices[i] = int.Parse(inputs[i]);
        }

        int result = MaxProfit(prices);
        Console.WriteLine("Maximum profit: " + result);
    }
}
