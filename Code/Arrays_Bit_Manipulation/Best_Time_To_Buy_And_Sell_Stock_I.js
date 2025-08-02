const readline = require('readline');

function maxProfit(prices) {
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
}

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Enter stock prices separated by space: ", (answer) => {
    const prices = answer.split(" ").map(Number);
    const result = maxProfit(prices);
    console.log("Maximum profit:", result);
    rl.close();
});
