package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

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

func main() {
    reader := bufio.NewReader(os.Stdin)
    fmt.Print("Enter stock prices separated by space: ")
    input, _ := reader.ReadString('\n')
    input = strings.TrimSpace(input)

    parts := strings.Split(input, " ")
    prices := make([]int, len(parts))

    for i, part := range parts {
        prices[i], _ = strconv.Atoi(part)
    }

    result := maxProfit(prices)
    fmt.Println("Maximum profit:", result)
}
